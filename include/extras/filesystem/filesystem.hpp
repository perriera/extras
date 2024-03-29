// /**
//  * @file filesystem.hpp
//  * @author Perry Anderson (perry@exparx.ca)
//  * @brief extra's std::filesystem methods, (for use with std::filesystem)
//  * @version 0.1
//  * @date 2021-11-30
//  *
//  * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
//  *
//  */

// #ifndef _EXTRAS_FILESYSTEM_HPP
// #define _EXTRAS_FILESYSTEM_HPP

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

// // #if __cplusplus >= 201703L
// // #include <filesystem>
// // #else
// // //
// //
// https://askubuntu.com/questions/1256440/how-to-get-libstdc-with-c17-filesystem-headers-on-ubuntu-18-bionic
// // #include <experimental/filesystem>
// // #endif

// // since C++ 20
// #include <version>

// #ifdef __cpp_lib_filesystem
// #define _HAS_CXX17 1
// #include <filesystem>
// #include <iostream>
// #elif __cpp_lib_experimental_filesystem
// #include <experimental/filesystem>
// #else
// #error "no filesystem support ='("
// #endif

// #include <extras/exceptions.hpp>
// #include <extras/language/interfaces.hpp>
// #include <extras/types.hpp>
// #include <iostream>
// #include <vector>

// namespace extras {

//   /**
//    * @brief FileSystemInterface
//    *
//    */

//   interface FileSystemInterface {
//     virtual const Path& path() const pure;
//     virtual const Pathname& pathname() const pure;
//     virtual const Filename& justthefilename() const pure;
//     virtual const Extension& justtheextension() const pure;
//     virtual const Filename& filename() const pure;
//     virtual Path prepend(const Directory& dir) const pure;
//     virtual Path append(const Directory& dir) const pure;
//   };

//   /**
//    * @brief FileSystem
//    *
//    */

//   class FileSystem implements FileSystemInterface {
//     Path strip_first(const Directory& dir) const;
//     Path strip_last(const Directory& dir) const;

//    public:
//     FileSystem(const Path& path);
//     virtual const Path& path() const override { return _path; };
//     virtual const Pathname& pathname() const override { return _pathname; };
//     virtual const Filename& justthefilename() const override {
//       return _justthefilename;
//     };
//     virtual const Extension& justtheextension() const override {
//       return _justtheextension;
//     };
//     virtual const Filename& filename() const override { return _filename; };
//     virtual Path prepend(const Directory& dir) const override;
//     virtual Path append(const Directory& dir) const override;

//    private:
//     Path _path;
//     Pathname _pathname;
//     Pathname _filename;
//     Filename _justthefilename;
//     Extension _justtheextension;
//   };

// }  // namespace extras

// #endif  // _EXTRAS_FILESYSTEM_HPP
