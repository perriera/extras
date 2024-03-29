/**
 * @file types.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief C++ defined type definitions specific to this package
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXTRA_TYPES_HPP
#define _EXTRA_TYPES_HPP

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

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

namespace extras {

   /**
    * @brief bytes
    *
    * " Of the same size as char, but guaranteed to be unsigned.
    *   Contains at least the [0, 255] range.[5] ""
    *    -- https://en.wikipedia.org/wiki/C_data_types
    *    -- Wikipedia, August 6, 2021
    *
    * [5]  ISO/IEC 9899:1999 specification, TC3 (PDF). p. 37,
    * § 6.2.6.1 Representations of types – General.
    *
    */

   using byte = unsigned char;
   using bytes = byte*;

   /**
    * @brief common types
    *
    * " Of the same size as char, but guaranteed to be unsigned.
    *   Contains at least the [0, 255] range.[5] ""
    *    -- https://en.wikipedia.org/wiki/C_data_types
    *    -- Wikipedia, August 6, 2021
    *
    * [5]  ISO/IEC 9899:1999 specification, TC3 (PDF). p. 37,
    * § 6.2.6.1 Representations of types – General.
    *
    */
   using Parameter = std::string;
   using Parameters = std::deque<Parameter>;
   using Filename = std::string;
   using Filenames = std::vector<Filename>;
   using Path = std::string;
   using Pathname = std::string;
   using Pathnames = std::vector<Filename>;
   using Extension = std::string;
   using Extensions = std::vector<Extension>;
   using Directory = std::string;
   using DirectoryListing = std::vector<Directory>;

} // namespace extras

#endif // _EXTRA_TYPES_HPP
