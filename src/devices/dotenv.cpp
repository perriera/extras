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

#include <extras/devices/dotenv.hpp>
#include <extras/strings.hpp>
#include <iomanip>
#include <iostream>

namespace extras {

   /**
    * @brief DotENVLineKeyException::assertion()
    *
    * @param out
    * @param obj
    * @return std::ostream&
    */

   void DotENVLineKeyException::assertion(const std::string& key,
                                          const WhereAmI& ref)
   {
      DotENVNoKeyException::assertion(key, ref);
      DotENVBadFormatException::assertion(key, ref);
   }

   /**
    * @brief DotENVNoKeyException::assertion()
    *
    * Thrown if no KEY is specified
    *
    * @param out
    * @param obj
    * @return std::ostream&
    */

   void DotENVNoKeyException::assertion(const std::string& key,
                                        const WhereAmI& ref)
   {
      if (key.length() == 0) {
         throw DotENVNoKeyException("No key specified", ref);
      }
   }

} // namespace extras
