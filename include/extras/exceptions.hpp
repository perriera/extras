#ifndef _EXTRA_EXCEPTIONS
#define _EXTRA_EXCEPTIONS

/**
 * @file exceptions.hpp
 *
 * @author Matt Williams, (matt@dmgblockchain.com)
 *
 * @brief CustomExceptionInterface is needed for polymorphic reasons,
 * passing exact error subclasses into functions is cumberson, I will
 * either have to template the function, or overload it. This way I can
 * just make a a AbstractCustomException pointer to the subclass in
 * question and pass that around instead. I'm also a huge fan of knowing
 * the file, function signature and line where the error happend, with
 * this being said an ADT isZnatural as it forces the CDT to give an
 * exact implementation.
 *
 * @version 1.0.0
 * @date 2021-08-11
 *
 * @copyright Copyright (c) 2021, Matt Williams, (MIT License)
 *
 */

#include <exception>
#include <extras/interfaces.hpp>
#include <iostream>
#include <string>

namespace extras {

  struct WhereAmI {
    std::string _file;
    std::string _func;
    int _line;
    WhereAmI(const std::string &file, const std::string &func, int line)
        : _file(file), _func(func), _line(line) {}
  };
  // namespace extras

#define __DATAONERROR__ \
  __FILE__, static_cast<const char *>(__PRETTY_FUNCTION__), __LINE__
#define __INFO__ \
  WhereAmI(__FILE__, static_cast<const char *>(__PRETTY_FUNCTION__), __LINE__)

  /**
   * @brief interface CustomExceptionInterface
   *
   * */

  interface CustomExceptionInterface {
    virtual const char *what() const noexcept pure;
    virtual const char *getfile() const noexcept pure;
    virtual const char *getfunc() const noexcept pure;
    virtual int getline() const noexcept pure;
  };

  /**
   * @brief class AbstractCustomException
   *
   * */

  abstract class AbstractCustomException extends std::exception with
      CustomExceptionInterface {
    friend std::ostream &operator<<(std::ostream &os,
                                    const AbstractCustomException &dt);

   protected:
    std::string _msg;
    std::string _file;
    std::string _func;
    int _line = 0;

   public:
    AbstractCustomException(const char *msg, const char *file, const char *func,
                            int line)
        : _msg(msg), _file(file), _func(func), _line(line) {}

    [[nodiscard]] const char *what() const noexcept override {
      return _msg.c_str();
    };
    [[nodiscard]] virtual const char *getfile() const noexcept {
      return _file.c_str();
    };
    [[nodiscard]] virtual const char *getfunc() const noexcept {
      return _func.c_str();
    };
    [[nodiscard]] virtual int getline() const noexcept { return _line; };
  };

  /**
   * @brief GeneralCustomException is the root of all the custom exceptions.
   * This is a good design, because if there is an area where the programmer
   * is not sure which exception will be thrown, catching LibdmgException will
   * automatically catch all the exceptions that inherit from it.
   */
  class GeneralCustomException : public AbstractCustomException {
   public:
    GeneralCustomException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
  };

  /**
   * @brief SpecificCustomException allows you to get very specific
   * about what actually happened to throw the exception. It usually
   * should have  it's 'msg' already defined, but you can specify
   * additional information that would be helpful to the overall
   * description of the custom exception.
   */

  class SpecificCustomException : public GeneralCustomException {
   public:
    SpecificCustomException(const WhereAmI &whereAmI)
        : GeneralCustomException("Specific custom exception description",
                                 whereAmI) {}
    SpecificCustomException(const char *param, const WhereAmI &whereAmI)
        : GeneralCustomException(param, whereAmI) {
      std::string msg_with_param;
      msg_with_param = "Port: ";
      msg_with_param += param;
      msg_with_param += " wasn't found";
      this->_msg = msg_with_param;
    }
    static void assertion(const std::string &filename, const WhereAmI &ref);
  };

}  // namespace extras

#endif  // _EXTRA_EXCEPTIONS