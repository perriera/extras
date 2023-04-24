/**
 * @rebrand FileInterface.hpp
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
   namespace rebrand {

      /**
       * @brief
       *
       */
      using Number = std::string;
      using Cmd = std::string;

      /**
       * @brief LoginInterface
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
         virtual Number major() const pure;
         virtual Number minor() const pure;
         virtual Number patch() const pure;

         /**
          * @brief
          *
          * @return Filename
          */
         virtual Filename rebranded() const pure;
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

   } // namespace rebrand
} // namespace extras

#endif // _EXTRAS_REBRAND_INTERFACE_HPP
