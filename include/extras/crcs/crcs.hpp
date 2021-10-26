#ifndef _EXTRA_CRCS_HPP
#define _EXTRA_CRCS_HPP

/**
 * @file crcs.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Defacto standard interface for CRCInterface.
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */
#include "extras/crcs/crc16_support.hpp"
#include "extras/crcs/crc32_support.hpp"
#include "extras/crcs/crc64_support.hpp"
#include "extras/keywords.hpp"
#include "extras/language/interfaces.hpp"

namespace extras {

  /**
   * @brief class CRCInterface
   *
   * Basic implementation for CRC calculations that demonstrates
   * two key concepts as described in GoF: Design Patterns, (1994)
   *
   * 1: https://en.wikipedia.org/wiki/Abstract_factory_pattern
   * 2: https://en.wikipedia.org/wiki/Singleton_pattern
   * 3: https://en.wikipedia.org/wiki/Strategy_pattern
   *
   * Where Polymorphism on both C++ method calls and return types
   * are clearly demonstrated with the CRCInterface as well
   * the CRC class implementation of the CRCInterface.
   *
   */
  interface CRCInterface {
    /**
     * Polymorphism on right side of methods in C++ is quite well known.
     *
     * CRC's are generally designed to work on binary arrays,
     * so two parameters are expected, (at least).
     */
    virtual const CRCInterface &calculate(const byte &buffer, int len) pure;

    /**
     * All two often a CRC is only needed on a string buffer which
     * reserves the '0x0' for null termination. Hence it provides it's
     * lenght vua it's lengh() method, (saving us a parameter).
     */
    virtual const CRCInterface &calculate(const std::string &str) pure;

    /**
     * Polymorphism on left side of methods in C++ is not so well known.
     *
     * Polymorphism is available in C++ by way of overloading the
     * expected return types. In this manner the same calculae method
     * for setting up the CRC instance will all operate on the same
     * buffer. Mind you, this may not be an ideal in threaded
     * environment, (see private: CRC() below).
     */
    virtual operator uint16_t() const pure;
    virtual operator uint32_t() const pure;
    virtual operator uint64_t() const pure;

    /**
     * @brief operator std::string() const pure
     *
     * While the defacto operator method most programmers are familiar with
     * when it comes to operator overloading, it really wouldn't make sense
     * here as it really wouldn't know what to return, (aka 16, 32 or 64?).
     *
     */
  };

  /**
   * @brief class CRC
   *
   * A good singleton only allows one method of creating an instance.
   * However, in a threaded environment intances will be needed, so
   * this implementation will make the default constructor protected
   * for none-threaded environments.
   *
   */
  concrete class CRC implements CRCInterface {
    std::string _str;
    const byte *_buffer = nullptr;
    int _len = 0;

   private:
    CRC(){};

   public:
    /**
     * The C++11 way of doing singletons ...
     */
    static auto instance() -> CRCInterface & {
      static CRC calculator;
      return calculator;
    }

    virtual const CRCInterface &calculate(const byte &buffer, int len) {
      this->_buffer = &buffer;
      this->_len = len;
      return *this;
    }

    virtual const CRCInterface &calculate(const std::string &str) {
      this->_str = str;
      return *this;
    };

    operator uint16_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
  };

  /**
   * @brief class ThreadedCRC
   *
   * In the ThreadedCRC implemnetation each instance will be able
   * to maintain it's own copy of crc16, crc32 and crc64. As this
   * class can also work in a non-threaded environment it won't be
   * as efficient, (because of it creating instances on demand
   * rather than just once). To be a Hitler about it, we could
   * add extra code to enforce this by implementating a singleton
   * instance() method here, (just to throw an exception), but we
   * have bigger fish to fry, (aka. "less code is more code").
   *
   * Note: The class is declared but the actual implementation
   *       is not required at the moment, (for future reference).
   *
   */
  concrete class ThreadedCRC implements CRCInterface {
   public:
    virtual const CRCInterface &calculate(const byte &buffer, int len);
    virtual const CRCInterface &calculate(const std::string &str);

    operator uint16_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
  };

}  // namespace extras

#endif  // _EXTRA_CRCS_HPP