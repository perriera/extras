// /**
//  * @brief The MIT License (MIT)
//  * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
//  * @ref https://github.com/perriera
//  *
//  * Permission  is  hereby  granted, free  of  charge, to  any person
//  obtaining
//  * a copy of this software and associated documentation files (the
//  “Software”),
//  * to deal in the Software  without restriction,  including  without
//  limitation
//  * the rights to  use,  copy,  modify,  merge, publish, distribute,
//  sublicense,
//  * and/or sell  copies of the  Software,  and  to  permit  persons  to whom
//  the
//  * Software is furnished to do so, subject to the following conditions:
//  *
//  * The above copyright notice  and this permission  notice shall be included
//  in
//  * all copies or substantial portions of the Software.
//  *
//  * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,
//  EXPRESS
//  * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY,
//  * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE
//  * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR
//  OTHER
//  * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE,
//  ARISING
//  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS
//  * IN THE SOFTWARE.
//  *
//  */

// #include <ctype.h>
// #include <extras/file/clazz.hpp>
// #include <extras/filesystem/files.hpp>
// #include <extras/strings/string_support.hpp>
// #include <fstream>
// #include <iostream>
// #include <regex>
// #include <string>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <unistd.h>

// using namespace std;
// using namespace extras;
// using namespace extras::file;

// /**
//  * @brief FolderExistsException::assertion
//  *
//  * @param fullpath
//  * @param ref
//  */
// void
// FolderExistsException::assertion(const Interface& file, const WhereAmI& ref)
// {
//    _assume(file.fullpath().length() == 0)
//      _ensure FolderNotSpecifiedException(ref);
//    auto fn = file.fullpath();
//    auto lastChar = fn[fn.length() - 1];
//    _assume(!isalnum(lastChar) && lastChar != '/')
//      _ensure NotAFolderNameException(fn, ref);
//    struct stat statbuf;
//    string name = file.fullpath();
//    _assume(stat(name.c_str(), &statbuf) != 0)
//      _ensure NotFoundException(name, ref);
//    _assume(!S_ISDIR(statbuf.st_mode))
//      _ensure NotAFolderException(file.fullpath(), ref);
// }

// void
// FolderExistsException::assertion(const Filename& fn, const WhereAmI& ref)
// {
//    file::File file(fn);
//    Interface& i = file;
//    assertion(i, ref);
// }

// /**
//  * @brief FolderNotFoundException::assertion
//  *
//  * @param fullpath
//  * @param ref
//  */
// void
// FolderNotFoundException::assertion(const Interface& i, const WhereAmI& ref)
// {
//    FolderExistsException::assertion(i, ref);
// }

// /**
//  * @brief NotaFolderException::assertion
//  *
//  * @param fullpath
//  * @param ref
//  */
// void
// NotaFolderException::assertion(const Interface&, const WhereAmI&)
// {
//    // struct stat statbuf;
//    // if (stat(fi.fullpath().c_str(), &statbuf) != 0)
//    //   throw NotaFolderException(fi.fullpath(), ref);
//    // if (!S_ISDIR(statbuf.st_mode)) throw NotaFolderException(fi.fullpath(),
//    // ref);
//    throw extras::feature::NotImplementedException(
//      "NotaFolderException::assertion()", __INFO__);
// }

// /**
//  * @brief NotaFileException::assertion
//  *
//  * @param fullpath
//  * @param ref
//  */
// void
// NotaFileException::assertion(const Interface&, const WhereAmI&)
// {
//    // ifstream f(fi.fullpath().c_str());
//    // if (!f.good()) throw NotaFileException(fi.fullpath(), ref);
//    throw extras::feature::NotImplementedException(
//      "NotaFileException::assertion()", __INFO__);
// }
