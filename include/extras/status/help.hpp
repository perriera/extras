/**
 * @file Help.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief HelpInterface
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXPARX_HELP_HPP
#define _EXPARX_HELP_HPP

/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 * @ref https://github.com/perriera
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

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

namespace extras {

   /**
    * @brief HelpInterface
    *
    * This interface is intended for command line utilities
    * that wish to add a help option.
    *
    */

   interface HelpInterface
   {
      virtual void help() const pure;
   };

} // namespace extras

#endif // _EXPARX_HELP_HPP
