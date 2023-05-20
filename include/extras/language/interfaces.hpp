/**
 * @file interfaces.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief interface keyword, (for use with Design by Interface)
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXTRA_LANGUAGE_INTERFACES_HPP
#define _EXTRA_LANGUAGE_INTERFACES_HPP

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

namespace extras {

///
/// What does “program to interfaces, not implementations” mean?
///

/**
 * @brief interface keyword
 * @ref https://en.wikipedia.org/wiki/Abstract_factory_pattern
 *
 * If a class is actually an interface this pseudo keyword
 * should be used instread of the more generic 'struct' keyword
 * as it is a better way to indicate that the struct is actually
 * being used for class abstraction purposes.
 */
#define interface struct

/**
 * @brief design_by_contract keyword
 * @ref https://en.wikipedia.org/wiki/Design_by_contract
 *
 * " Design by contract (DbC), also known as contract programming,
 *   programming by contract and design-by-contract programming,
 *   is an approach for designing software. ""
 *   -- Wikipedia, August 6th, 2021
 *
 * It's a more formal version of the 'interface' keyword but
 * intended for business level classes, (whereas the 'interface'
 * keyword is intended for system interface classes). As this
 * keyword implies there will be a 'precondition' and then
 * 'postcondition' and perhaps 'when' method to be found
 * somewhere in your interface declaration.
 *
 * design_by_contract is a throw back to the days of more formal
 * Use Case driven software development.
 *
 */
#define design_by_contract struct

/**
 * @brief Interface driven design
 * @ref https://en.wikipedia.org/wiki/Design_Patterns
 *
 * Interfaces are just contracts or signatures and they don't
 * know anything about implementations.
 *
 * Coding against interface means, the client code always holds
 * an Interface object which is supplied by a factory. Any instance
 * returned by the factory would be of type Interface which any
 * factory candidate class must have implemented. This way the
 * client program is not worried about implementation and the
 * interface signature determines what all operations can be done.
 * This can be used to change the behavior of a program at run-time.
 * It also helps you to write far better programs from the
 * maintenance point of view.
 *
 * @ref
 * https://stackoverflow.com/questions/2697783/what-does-program-to-interfaces-not-implementations-mean
 *
 */

/**
 * @brief Software design pattern
 * @ref https://en.wikipedia.org/wiki/Software_design_pattern
 *
 * To better facilitate more modern programming methods we
 * add pseudo keywords to alert the programmer of what is
 * intended in the source code, (being viewed/edited).
 *
 */

/**
 * @brief abstract keyword
 * @ref https://en.wikipedia.org/wiki/Factory_method_pattern
 *
 * If a class is abstract this pseudo keyword should be
 * placed in front of it to better indicate that the class
 * is an abstract class.
 */
#define abstract

/**
 * @brief concrete keyword
 * @ref https://en.wikipedia.org/wiki/Factory_method_pattern
 *
 * If a class is concrete this pseudo keyword should be
 * placed in front of it to better indicate that the class
 * is an concrete class.
 */
#define concrete

/**
 * @brief extends keyword
 *
 * If a class 'extends' another base class it is better to use
 * this keyword, (where possible)
 *
 */
#define extends :   public

/**
 * @brief implements keyword
 *
 * If a class 'implements' an 'interface' then it should have this
 * keyword following it's declaration
 *
 */
#define implements extends

/**
 * @brief pure keyword
 *
 * Ideally, an interface only consists of pure virtual functions.
 * Hence, all methods declared using the 'interface' keyword should
 * have a 'pure' keyword at the end of each signature.
 *
 * Whenever the C++ complains of missing methods in vtable the first
 * thing to look for is whether the keyword 'pure' is at the end of
 * each of your methods declared in the interface.
 *
 */
#define pure = 0

/**
 * @brief with keyword
 *
 * Where possible use the 'with' keyword rather than the ',' to
 * include more than one interface for a class as it is better
 * for clarity and it implies that you are using an interface.
 *
 */
#define with , public

/**
 * @brief assume (glorified 'assert')
 *
 *     assume (the condition does NOT exist)
 *        otherwise throw an exception
 */
#define _assume if
#define _ensure throw

} // namespace extras

#endif // _EXTRA_LANGUAGE_INTERFACES_HPP
