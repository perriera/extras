#ifndef _EXTRA_EXCEPTIONS
#define _EXTRA_EXCEPTIONS

/**
 * @file libdmg_exceptions.hpp
 * @author Matt Williams, (matt@dmgblockchain.com)
 * @brief Abstract pure virtual exception base class is needed for polymorphic
 * reasons, passing exact error subclasses into functions is cumberson, I will
 * either have to template the function, or overload it. This way I can just
 * make a a LibdmgAbstractException pointer to the subclass in question and pass
 * that around instead. I'm also a huge fan of knowing the file, function
 *  signature and line where the error happend, with this being said an ADT is
 * natural as it forces the CDT to give an exact implementation.
 *
 * @version 0.1
 * @date 2021-07-28
 *
 * @copyright Copyright (c) 2021
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
    WhereAmI(const std::string &file, const std::string &func, int line);
  };

#define __DATAONERROR__ \
  __FILE__, static_cast<const char *>(__PRETTY_FUNCTION__), __LINE__
#define __INFO__                                                             \
  libdmg::WhereAmI(__FILE__, static_cast<const char *>(__PRETTY_FUNCTION__), \
                   __LINE__)

  /**
   * @brief interface LibdmgExceptionInterface
   *
   * */

  interface ExceptionInterface {
    virtual const char *what() const noexcept pure;
    virtual const char *getfile() const noexcept pure;
    virtual const char *getfunc() const noexcept pure;
    virtual int getline() const noexcept pure;
  };

  /**
   * @brief class LibdmgAbstractException
   *
   * */

  abstract class AbstractException extends std::exception with
      ExceptionInterface {
    friend std::ostream &operator<<(std::ostream &os,
                                    const AbstractException &dt);

    std::string _msg;
    std::string _file;
    std::string _func;
    int _line = 0;

   public:
    AbstractException(const char *msg, const char *file, const char *func,
                      int line);
    AbstractException(std::string &msg, const char *file, const char *func,
                      int line);

    explicit AbstractException(const char *msg);
    explicit AbstractException(std::string &msg);

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

  /** @info: LibdmgException is the root of all the custom exceptions. This is a
   * good design, because if there is an area where the programmer is not sure
   * which exception will be thrown, catching LibdmgException will automatically
   * catch all the exceptions that inherit from it.
   * */
  class Exception : public AbstractException {
   public:
    Exception(const char *_msg, const char *_file, const char *_func,
              int _line);
    Exception(std::string &_msg, const char *_file, const char *_func,
              int _line);

    explicit Exception(const char *_msg);
    explicit Exception(std::string &_msg);
  };

}  // namespace extras

#endif  // _EXTRA_EXCEPTIONS