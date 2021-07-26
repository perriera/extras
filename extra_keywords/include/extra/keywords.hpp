#ifndef _EXTRA_KEYWORDS_HPP
#define _EXTRA_KEYWORDS_HPP

/**
 * @file keywords.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Adds unique keywords to the C++ programming language
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */

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

#endif // _EXTRA_KEYWORDS_HPP