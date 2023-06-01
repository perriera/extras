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

#include "../../test/vendor/catch.hpp"
#include "../../test/vendor/fakeit.hpp"

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <extras/retag/interface.hpp>
#include <extras/strings.hpp>
#include <extras/version.hpp>
#include <iostream>
#include <sstream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras::retag;
using namespace extras;
using namespace fakeit;

/**
 * @brief dock retag::Interface
 *
 */
SCENARIO("Mold retag::Interface", "[mold retag::Interface]")
{

   /**
    * @brief members variables
    *
    */
   Filename _sharedlibraryname;
   Filename _major_minor_patch;

   /**
    * @brief determine _fullpath
    *
    */
   Number _major_no;
   Number _minor_no;
   Number _patch_no;
   Filename testarea = "build/testarea/";
   Filename filename = "libsisutil.so";
   Filename _fullpath = testarea + filename;
   Filename symlink1 = _fullpath + "." + _major_no;
   Filename symlink2 = symlink1 + "." + _minor_no;
   Filename symlink3 = symlink2 + "." + _patch_no;
   Filename before = testarea + filename;
   Filename after = symlink3;

   /**
    * @brief construct dock for interface
    *
    */
   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, parameters))
     .AlwaysDo([&i,
                &_sharedlibraryname,
                &_major_minor_patch,
                &_major_no,
                &_minor_no,
                &_patch_no](int argc, const char* argv[]) {
        ParameterList _list;
        for (int j = 0; j < argc; j++)
           _list.push_back(argv[j]);
        IncorrectParametersException::assertion(_list, __INFO__);
        _sharedlibraryname = _list[0];
        _major_minor_patch = _list[1];
        file::NotFoundException::assertion(_sharedlibraryname, __INFO__);
        auto parts = extras::str::split(_major_minor_patch, ".");
        IncorrectNumbersException::assertion(parts, __INFO__);
     });
   When(Method(mold, execute))
     .AlwaysDo([&i, &_sharedlibraryname, &_major_minor_patch]() {
        extras::file::File file(_sharedlibraryname);
        Pathname original = file.filename();
        Pathname symlink1 = original + "." + i.major_no();
        Pathname symlink2 = symlink1 + "." + i.minor_no();
        Pathname symlink3 = symlink2 + "." + i.patch_no();
        Pathname script_name = file.tempname("retag.XXXXXX");
        {
           std::ofstream script(script_name);
           script << "cd " << file.pathname() << std::endl;
           script << "rm " << symlink3 << " 2>/dev/null" << std::endl;
           script << "rm " << symlink2 << " 2>/dev/null" << std::endl;
           script << "rm " << symlink1 << " 2>/dev/null" << std::endl;
           script << "mv " << original << ' ' << symlink3 << std::endl;
           script << "ln -s " << symlink3 << ' ' << symlink2 << std::endl;
           script << "ln -s " << symlink2 << ' ' << symlink1 << std::endl;
           script << "ln -s " << symlink1 << ' ' << original << std::endl;
        }
        Cmd cat = "cat " + script_name;
        system(cat.c_str());
        Cmd bash = "bash " + script_name;
        system(bash.c_str());
        Cmd rm = "rm " + script_name;
        system(rm.c_str());
        std::cout << std::endl;
     });
   When(Method(mold, major_no)).AlwaysDo([&_major_no]() {
      {
         return _major_no;
      }
   });
   When(Method(mold, minor_no)).AlwaysDo([&_minor_no]() {
      {
         return _minor_no;
      }
   });
   When(Method(mold, patch_no)).AlwaysDo([&_patch_no]() {
      {
         return _patch_no;
      }
   });
   When(Method(mold, newTag)).AlwaysDo([&i, &_fullpath]() {
      extras::file::File file(_fullpath);
      auto filename = file.filename();
      filename += "." + i.major_no();
      filename += "." + i.minor_no();
      filename += "." + i.patch_no();
      filename = file.pathname() + filename;
      return filename;
   });

   /**
    * @brief prepare test area
    *
    */

   // test_parameters(i);
   // test_execute(i);

   /**
    * @brief verify the desired methods were tested
    *
    */
   // Verify(Method(mold, parameters));
   // Verify(Method(mold, execute));
   // Verify(Method(mold, major_no));
   // Verify(Method(mold, minor_no));
   // Verify(Method(mold, patch_no));
}
