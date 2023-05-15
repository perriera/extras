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

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

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
    * @brief determine _fullpath
    *
    */
   Number major_no = std::to_string(EXTRAS_VER_MAJOR);
   Number minor_no = std::to_string(EXTRAS_VER_MINOR);
   Number patch_no = std::to_string(EXTRAS_VER_PATCH);
   Filename testarea = "build/testarea/";
   Filename filename = "libsisutil.so";
   Filename _fullpath = testarea + filename;
   Filename symlink1 = _fullpath + "." + major_no;
   Filename symlink2 = symlink1 + "." + minor_no;
   Filename symlink3 = symlink2 + "." + patch_no;
   Filename before = testarea + filename;
   Filename after = symlink3;

   /**
    * @brief construct dock for interface
    *
    */
   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, execute)).AlwaysDo([&i, &_fullpath]() {
      extras::file::File file(_fullpath);
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
   When(Method(mold, parameters))
     .AlwaysDo([&i, &_fullpath](int argc, const char* argv[]) {
        extras::file::File file(_fullpath);
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
   When(Method(mold, major_no)).AlwaysDo([&major_no]() {
      {
         return major_no;
      }
   });
   When(Method(mold, minor_no)).AlwaysDo([&minor_no]() {
      {
         return minor_no;
      }
   });
   When(Method(mold, patch_no)).AlwaysDo([&patch_no]() {
      {
         return patch_no;
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

   test_execute(i);
   test_parameters(i);

   /**
    * @brief verify the desired methods were tested
    *
    */
   Verify(Method(mold, execute));
   Verify(Method(mold, major_no));
   Verify(Method(mold, minor_no));
   Verify(Method(mold, patch_no));
}
