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

#include "../../../test/vendor/catch.hpp"
#include "../../../test/vendor/fakeit.hpp"

#include <extras/docking/DockIt.hpp>
#include <extras/filesystem/path/interface.hpp>
#include <fstream>
#include <iostream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

// Filename _current_path_filename() /*const*/ {
//   // fs::current_path().filename();
//   throw "not implelmented yet";
// }

// Filename _path(const Filename& before) /*const*/ {
//   // fs::current_path().filename();
//   throw "not implelmented yet";
// }

// Filename _path_filename(const Filename& before) /*const*/ {
//   // fs::path(item).filename();
//   throw "not implelmented yet";
// }

// Filename _directory_iterator(const Directory& src) /*const*/ {
//   // fs::directory_iterator(_src)
//   throw "not implelmented yet";
// }

/**
 *
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Dock extras::fs::path::Interface", "[extras::fs::path::Interface]")
{

   /**
    * @brief
    *
    */
   auto correct_answer = "/home/perry/Downloads";
   Mold<fs::path::Interface> dock;
   fs::path::Interface& i = dock.get();
   When(Method(dock, path)).AlwaysDo([&correct_answer](const Filename&) {
      {
         system("pwd > /tmp/output.txt");
         std::ifstream in("/tmp/output.txt");
         std::string line;
         std::getline(in, line);
         return correct_answer;
      }
   });
   When(Method(dock, current_path_filename)).AlwaysDo([&correct_answer]() {
      {
         system("pwd > /tmp/output.txt");
         std::ifstream in("/tmp/output.txt");
         std::string line;
         std::getline(in, line);
         return correct_answer;
      }
   });
   When(Method(dock, path_filename))
     .AlwaysDo([&correct_answer](const Filename&) {
        {
           system("pwd > /tmp/output.txt");
           std::ifstream in("/tmp/output.txt");
           std::string line;
           std::getline(in, line);
           return correct_answer;
        }
     });
   When(Method(dock, directory_iterator))
     .AlwaysDo([&correct_answer](const Filename&) {
        {
           system("pwd > /tmp/output.txt");
           std::ifstream in("/tmp/output.txt");
           std::string line;
           std::getline(in, line);
           return correct_answer;
        }
     });

   /**
    * @brief
    *
    */

   REQUIRE(i.path("filename") == correct_answer);
   REQUIRE(i.path_filename("filename") == correct_answer);
   REQUIRE(i.current_path_filename() == correct_answer);
   REQUIRE(i.directory_iterator("filename") == correct_answer);

   /**
    * @brief Construct a new Verify object
    *
    */
   Verify(Method(dock, path));
   Verify(Method(dock, path_filename));
   Verify(Method(dock, current_path_filename));
   Verify(Method(dock, directory_iterator));
}
