/**
 * @retag FileInterface.hpp
 * @author Perry Anderson (perryand@yorku.ca)
 * @brief define standard methods for FileInterface
 * @version 0.1
 * @date 2022-07-29
 *
 * @copyright (C) Friday, July 29, 2022 EXPARX, Inc.
 *
 */

#ifndef _EXTRAS_REBRAND_INTERFACE_HPP
#define _EXTRAS_REBRAND_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
   namespace retag {

      /**
       * @brief
       *
       */
      using Number = std::string;
      using Cmd = std::string;

      /**
       * @brief retag::Interface
       *
       */
      interface Interface
      {

         /**
          * @brief execute
          *
          */
         virtual void execute() const pure;

         /**
          * @brief major, minor, patch
          *
          * @return Number
          */
         virtual Number major_no() const pure;
         virtual Number minor_no() const pure;
         virtual Number patch_no() const pure;

         /**
          * @brief
          *
          * @return Filename
          */
         virtual Filename newTag() const pure;
      };

      /**
       * @brief FileException
       *
       */
      concrete class Exception extends extras::AbstractCustomException
      {
       protected:

         Exception(const std::string& msg, const extras::WhereAmI& whereAmI)
           : AbstractCustomException(msg.c_str(),
                                     whereAmI._file.c_str(),
                                     whereAmI._func.c_str(),
                                     whereAmI._line)
         {
         }
      };

      /**
       * @brief FileNotFoundException
       *
       */
      concrete class NotFoundException extends Exception
      {
       public:

         NotFoundException(const std::string& msg,
                           const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const Filename& filename,
                               const extras::WhereAmI& ref);
      };

   } // namespace retag
} // namespace extras

#endif // _EXTRAS_REBRAND_INTERFACE_HPP
