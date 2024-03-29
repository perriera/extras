/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 * @ref https://github.com/perriera
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#ifndef _EXTRAS_FEATURE_INTERFACE_HPP
#define _EXTRAS_FEATURE_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
   namespace feature {

      /**
       * @brief LoginInterface
       *
       */
      interface FeatureInterface
      {
      };

      /**
       * @brief feature::Exception
       *
       */
      concrete class FeatureException extends extras::AbstractCustomException
      {
       public:

         FeatureException(const std::string& msg,
                          const extras::WhereAmI& whereAmI)
           : AbstractCustomException(msg.c_str(),
                                     whereAmI._file.c_str(),
                                     whereAmI._func.c_str(),
                                     whereAmI._line)
         {
         }
      };

      /**
       * @brief NotImplementedException
       *
       */
      concrete class NotImplementedException extends FeatureException
      {
       public:

         NotImplementedException(const std::string& msg,
                                 const extras::WhereAmI& whereAmI)
           : FeatureException(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }
      };

   } // namespace feature
} // namespace extras

#endif // _EXTRAS_FEATURE_INTERFACE_HPP
