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

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using namespace extras::file;

/**
 * @brief file::Interface NotFoundException
 *
 */
SCENARIO("mold file::Interface::path", "[dock file::Interface]")
{

   /**
    * @brief test case #1
    *
    */

   extras::Pathname pathname = "test/file/etc/";
   extras::Filename filename = "some_file.txt";
   extras::Filename fullpath = pathname + filename;
   {
      extras::file::File dock(fullpath);
      Interface& i = dock;

      REQUIRE(extras::str::starts_with(i.tempname(""), "/tmp/mytemp."));
      REQUIRE(extras::str::starts_with(i.tempname("sample.XXXXXX"), "sample."));
      REQUIRE(i.pathname() == pathname);
      REQUIRE(i.filename() == filename);
      REQUIRE(i.fullpath() == fullpath);
      REQUIRE_FALSE(i.exists());
      REQUIRE_FALSE(i.is_dir());
      REQUIRE_FALSE(i.is_file());

      auto tn = i.tmpFile();
      REQUIRE(!tn.empty());
      extras::file::NotFoundException(tn, __INFO__);

      {
         extras::file::DeleteAfterUse rm_cmd(tn);
         extras::file::FoundException::assertion(tn, __INFO__);
         std::string mkdir = "mkdir " + tn;
         system(mkdir.c_str());
         extras::file::NotFoundException::assertion(tn, __INFO__);
      }
      extras::file::FoundException::assertion(tn, __INFO__);
   }

   /**
    * @brief test case #2
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/retag/librandom.sol build/testarea/librandom.so");
   pathname = "build/testarea/";
   filename = "librandom.so";
   fullpath = pathname + filename;
   {
      extras::file::File dock(fullpath);
      Interface& i = dock;

      REQUIRE(i.pathname() == pathname);
      REQUIRE(i.filename() == filename);
      REQUIRE(i.fullpath() == fullpath);
      REQUIRE(i.exists());
      REQUIRE_FALSE(i.is_dir());
      REQUIRE(i.is_file());
   }
}
