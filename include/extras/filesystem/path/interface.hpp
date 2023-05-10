/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
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

#ifndef _EXTRA_PATH_INTERFACE_HPP_
#define _EXTRA_PATH_INTERFACE_HPP_

#include <extras/interfaces.hpp>
#include <iostream>
#include <set>

namespace extras {

   namespace fs {
      namespace path {

         /**
          * @brief namespace base
          *
          */

         using Path = std::string;

         interface Interface
         {

            /**
             * @brief
             *
             * @return Path
             */
            virtual Path current_path_filename() const pure;

            /**
             * @brief
             *
             * @param before
             * @return Filename
             */
            virtual Path path(const Filename& before) const pure;

            /**
             * @brief
             *
             * @param before
             * @return Filename
             */
            virtual Filename path_filename(const Filename& before) const pure;

            /**
             * @brief
             *
             * @param src
             * @return Filename
             */
            virtual Filename directory_iterator(
              const Directory& src) const pure;
         };

         /**
          * @brief base::Exception
          *
          */

         concrete class Exception extends extras::AbstractCustomException
         {
          public:

            Exception(const std::string& msg, const extras::WhereAmI& whereAmI)
              : AbstractCustomException(msg.c_str(),
                                        whereAmI._file.c_str(),
                                        whereAmI._func.c_str(),
                                        whereAmI._line)
            {
            }
         };

      } // namespace path
   }    // namespace fs
} // namespace extras

#endif // _EXTRA_PATH_INTERFACE_HPP_
