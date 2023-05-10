// /**
//  * @file files.hpp
//  * @author Perry Anderson (perry@exparx.com)
//  * @brief DirectoryInterface, (deperacated in lue of C++11/std::filesystem)
//  * @version 0.1
//  * @date 2021-11-30
//  *
//  * @copyright (C) November 22, 2021 EXPARX INCORPORATED
//  *
//  */

// #ifndef _EXTRA_DIRECTORY_HPP
// #define _EXTRA_DIRECTORY_HPP

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

// #include <extras/exceptions.hpp>
// #include <extras/language/interfaces.hpp>
// #include <iostream>
// #include <vector>

// namespace extras {

//   /**
//    * @brief DirectoryInterface
//    *
//    */

//   typedef std::string Path;
//   typedef std::vector<std::string> Listing;

//   interface DirectoryInterface {
//     virtual const Path &path() const pure;
//     virtual const Listing &listing() const pure;
//     virtual std::string filename() const pure;
//     virtual std::string pathname() const pure;
//     virtual bool fileExists() const pure;
//   };

//   class Directory implements DirectoryInterface {
//    public:
//     Directory(const Path &path);

//     virtual const Path &path() const { return _path; }
//     virtual const Listing &listing() const { return _listing; }
//     virtual std::string filename() const;
//     virtual std::string pathname() const;
//     virtual bool fileExists() const;
//     virtual void copyTo(const Directory &pathname) const;
//     virtual void remove() const;

//    private:
//     Path _path;
//     Listing _listing;
//   };

// }  // namespace extras

// #endif  // _EXTRA_DIRECTORY_HPP
