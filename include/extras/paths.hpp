#ifndef _EXTRA_PATHS_HPP
#define _EXTRA_PATHS_HPP

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief PathsInterface
   *
   */

  interface PathsInterface {
    /**
     * @brief actualPath
     * @return replace the '~' with the value gained from getenv('home')
     * @exception invalid path supplied
     */
    virtual std::string actualPath(const std::string &path) const pure;
  };

  /**
   * @brief PathsInterface
   *
   */

  concrete class Paths implements PathsInterface {
    std::string _path;

   public:
    /**
     * @brief actualPath
     * @return replace the '~' with the value gained from getenv('home')
     * @exception invalid path supplied
     */
    virtual std::string actualPath(const std::string &path) const override;

    static auto instance() -> PathsInterface & {
      static Paths paths;
      return paths;
    }

    Paths(){};
    Paths(const std::string &path) : _path(path){};

    /**
     * @brief overloaded ~() operator to remove the ~ from the path
     * @return the full path, (where the '~' is replaced with home path)
     */
    Paths &operator~() noexcept { return *this; }
    operator std::string() { return actualPath(_path); }
  };

  /**
   * @brief OctalException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class PathsException extends AbstractCustomException {
   public:
    PathsException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &row_col, const WhereAmI &ref) {
      if (row_col.length() != 2 || row_col[0] < 'a' || row_col[0] > 'h' ||
          row_col[1] < '0' || row_col[0] > '7') {
        throw PathsException(row_col.c_str(), ref);
      }
    }
    static void assertion(int octalValue, const WhereAmI &ref) {
      if (octalValue < 0 || octalValue > 7) {
        throw SpecificCustomException(std::to_string(octalValue).c_str(), ref);
      }
    }
  };

}  // namespace extras

#endif  // _EXTRA_PATHS_HPP
