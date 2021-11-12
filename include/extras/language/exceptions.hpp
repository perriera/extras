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
 * @see test/mock_exceptions.cpp & test/test_exceptions.cpp
 *
 * @version 1.0.0
 * @date 2021-08-11
 *
 * @copyright Copyright (c) 2021, Matt Williams, (MIT License)
 *
 */

#include <cxxabi.h>

#include <cstdlib>
#include <exception>
#include <extras/language/interfaces.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>

namespace extras {

  /**
   * @brief struct extras::WhereAmI
   *
   * Used to capture all information related to the exception
   * in the source code and relay that inforation thry the custom
   * exception object hierarchy.
   *
   */
  struct WhereAmI {
    std::string _file;
    std::string _func;
    int _line;
    WhereAmI(const std::string &file, const std::string &func, int line)
        : _file(file), _func(func), _line(line) {}
  };
  // namespace extras

/**
 * @brief __INFO__
 *
 * The actual macro that does all the dancing when it comes to capturing
 * compiler generated information as to the file, function and line of
 * source where the exception happened. Must be compiled at runtime where
 * the exception is actually used so that the MACRO can be resolved properly.
 *
 * Given the general nature of the name chosen '__INFO__' alternative names
 * can be used, (send us an email as indicated in the README.md)
 *
 */
#define __INFO__                                                             \
  extras::WhereAmI(__FILE__, static_cast<const char *>(__PRETTY_FUNCTION__), \
                   __LINE__)

  /**
   * @brief interface CustomExceptionInterface
   *
   * */

  interface CustomExceptionInterface {
    /**
     * @brief Return what() happened
     *
     * This method has to wire straight into the C++11 std::exception
     * method of the same name. It cannot throw an exception but it
     * must be descriptive to the end user.
     *
     * @return const char*
     */
    virtual const char *what() const noexcept pure;

    /**
     * @brief Return __FILE__ information.
     *
     * All to often an exception is thrown and the relevant name of
     * the source file where it was generated is not mentioned. Using
     * the C/C++ macro __FILE__ we can pass this information on to
     * the end users.
     *
     * @return const char*
     */
    virtual const char *getfile() const noexcept pure;

    /**
     * @brief Return __func__ information.
     *
     * All to often an exception is thrown and the relevant name of
     * the source function/method where it was generated is not mentioned.
     * Using the C/C++ macro __FILE__ we can pass this information on to
     * the end users.
     *
     * @return const char*
     */
    virtual const char *getfunc() const noexcept pure;

    /**
     * @brief Return __LINE__ information.
     *
     * All to often an exception is thrown and the relevant name of
     * the source line where it was generated is not mentioned. Using
     * the C/C++ macro __LINE__ we can pass this information on to
     * the end users.
     *
     * @return const char*
     */
    virtual int getline() const noexcept pure;
    virtual std::string getwhat() const noexcept pure;

    /**
     * @brief static void assertion(... const WhereAmI &ref);
     *
     * Each custom exception the implements this interface should
     * implement, (at the static level) a dedicated method that will
     * generate the custom exception, (given a set of parameters).
     *
     * The reason why you want to do this is to both localized the
     * necessary conditions that would generate the custom exception
     * as well as simplify the client code where the exception is in
     * use. In the event of a different set of conditions required
     * to generate the custom exception, a seperate assertion() method
     * should be supplied. To effectively test this method in a test
     * case enviroment should employ (yet) another virtual method that
     * the static version would utilize, (which is up to your formal
     * test driven development policy descretion).
     *
     * @param ...
     * @param ref
     */
  };

  /**
   * @brief class AbstractCustomException
   *
   * While not an abstract class in this implementation, it is an
   * abstract such that it recommends supported classes implement
   * at least one static assertion(...) method.
   *
   * */

  abstract class AbstractCustomException extends std::exception with
      CustomExceptionInterface {
    friend std::ostream &operator<<(std::ostream &os,
                                    const AbstractCustomException &dt);
    static std::string _lastThrownException;

   protected:
    std::string _msg;
    std::string _file;
    std::string _func;
    int _line = 0;

    std::string demangle(char const *mangled) const {
      auto ptr = std::unique_ptr<char, decltype(&std::free)>{
          abi::__cxa_demangle(mangled, nullptr, nullptr, nullptr), std::free};
      return {ptr.get()};
    }

   public:
    AbstractCustomException(const char *msg, const char *file, const char *func,
                            int line)
        : _msg(msg), _file(file), _func(func), _line(line) {}

    [[nodiscard]] const char *what() const noexcept override {
      _lastThrownException = getwhat();
      _lastThrownException = demangle(_lastThrownException.c_str());
      _lastThrownException = _lastThrownException + ": " + _msg;
      return _lastThrownException.c_str();
    };
    [[nodiscard]] virtual const char *getfile() const noexcept override {
      return _file.c_str();
    };
    [[nodiscard]] virtual const char *getfunc() const noexcept override {
      return _func.c_str();
    };
    [[nodiscard]] virtual int getline() const noexcept override {
      return _line;
    };
    [[nodiscard]] virtual std::string getwhat() const noexcept override {
      return typeid(*this).name();
    };

    /**
     * @brief static void assertion(const std::string &filename, const WhereAmI
     * &ref);
     *
     * This is where we have to deal with the 'static' nature of 'static'
     * methods and the 'interface' nature of Test Driven Development, (TDD). TDD
     * does not like testing static methods. However, the 'assertion()'
     * **should** be implemented for all custom exceptions. It does not make
     * sense to setup a static assertion method for the AbstractCustomException
     * however, it does make sense to setup a static assertion(...) method for
     * the GroupCustomException that you would want for the optional grouping of
     * exceptions in your app.
     */
  };

  /**
   * @brief GroupCustomException is the root of all the custom exceptions.
   * This is a good design, because if there is an area where the programmer
   * is not sure which exception will be thrown, catching LibdmgException will
   * automatically catch all the exceptions that inherit from it.
   *
   * In your application you would define your own groups of exception classes.
   * In a small framework this might be counterproductive. In a large project,
   * (or one expected to grow), mitigating groups of exceptions with their own
   * 'family' named exception parent can help when catching exceptions.
   *
   */
  concrete class GroupCustomException extends AbstractCustomException {
   public:
    GroupCustomException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &filename, const WhereAmI &ref);
  };

  /**
   * @brief SpecificCustomException allows you to get very specific
   * about what actually happened to throw the exception. It usually
   * should have  it's 'msg' already defined, but you can specify
   * additional information that would be helpful to the overall
   * description of the custom exception.
   *
   * Whether you derive your specific custom exceptions from a group
   * (or 'family' name) or directly from the AbstractCustomException
   * depends on the size, (and nature) of your application. Either way,
   * you can now make life easier for yourself by having your program
   * throw specific exceptions for specific conditions. Having a well
   * named custom exception being generated with relavant information
   * can be a great time saver.
   *
   */

  concrete class SpecificCustomException extends GroupCustomException {
    std::string msg_with_parameter(const std::string &param) {
      std::string msg_with_param;
      msg_with_param = "Port: ";
      msg_with_param += param;
      msg_with_param += " wasn't found";
      return msg_with_param;
    }

   public:
    /**
     * @brief Construct a new Specific Custom Exception object
     *
     * @param whereAmI
     */
    SpecificCustomException(const WhereAmI &whereAmI)
        : GroupCustomException("Specific custom exception description",
                               whereAmI) {}

    /**
     * @brief Construct a new Specific Custom Exception object with addition
     * information, (that can be helpful)
     *
     * @param param
     * @param whereAmI
     */
    SpecificCustomException(const std::string &param, const WhereAmI &whereAmI)
        : GroupCustomException(msg_with_parameter(param).c_str(), whereAmI) {}

    /**
     * @brief static void assertion(...)
     *
     * To make life simpler for yourself, call a static assertion(...) on
     * the custom exception, (as oppose to repeating tests for conditions
     * the normally throw a particular custom exception all over your code).
     *
     * In this way you generally hit two birds wth one stone. However, if
     * there are more than one situation, (or set of conditions) that throw
     * the custom exception, then you need addtional assertion() methods.
     *
     * @param param
     * @param ref
     */
    static void assertion(const std::string &param, const WhereAmI &ref) {
      if (std::stoi(param) < 1024)
        throw SpecificCustomException(param.c_str(), ref);
    }
    static void assertion(int a, int b, const WhereAmI &ref) {
      if (a < b) {
        std::string params = "a<b";
        throw SpecificCustomException(params.c_str(), ref);
      }
    }
  };

}  // namespace extras

#endif  // _EXTRA_EXCEPTIONS