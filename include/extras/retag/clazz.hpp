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

#ifndef _EXTRAS_REBRAND_CLAZZ_HPP
#define _EXTRAS_REBRAND_CLAZZ_HPP

#include <bits/stdc++.h>
#include <extras/retag/interface.hpp>
#include <iostream>
#include <sstream>

struct user_id;
struct ldap;

namespace extras {
   namespace retag {

      /**
       * @brief retag::Interface
       *
       */
      concrete class Instance implements Interface
      {

         Filename _fullpath;
         Number _major_no;
         Number _minor_no;
         Number _patch_no;

       public:

         /**
          * @brief Construct a new Instance object
          *
          * @param fullpath
          */
         Instance(const Filename& fullpath,
                  const Number& major_no,
                  const Number& minor_no,
                  const Number& patch_no)
           : _fullpath(fullpath)
           , _major_no(major_no)
           , _minor_no(minor_no)
           , _patch_no(patch_no)
         {
         }

         /**
          * @brief execute
          *
          */
         virtual void execute() const
         {
            extras::file::File file(_fullpath);
            Pathname original = file.filename();
            Pathname symlink1 = original + "." + this->major_no();
            Pathname symlink2 = symlink1 + "." + this->minor_no();
            Pathname symlink3 = symlink2 + "." + this->patch_no();
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
         };

         /**
          * @brief major, minor, patch
          *
          * @return Number
          */
         virtual Number major_no() const { return _major_no; };

         virtual Number minor_no() const { return _minor_no; };

         virtual Number patch_no() const { return _patch_no; };

         /**
          * @brief
          *
          * @return Filename
          */
         virtual Filename newTag() const
         {
            extras::file::File file(_fullpath);
            auto filename = file.filename();
            filename += "." + this->major_no();
            filename += "." + this->minor_no();
            filename += "." + this->patch_no();
            filename = file.pathname() + filename;
            return filename;
         };
      };

   } // namespace retag
} // namespace extras

#endif // _EXTRAS_REBRAND_CLAZZ_HPP
