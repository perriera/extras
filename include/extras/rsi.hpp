#ifndef _EXTRA_RSI_HPP
#define _EXTRA_RSI_HPP

/**
 * @file rsi.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Remote Servicea Invocation, (RSI)
 *
 * @note In the interest of protecting proprietary information, (including
 * source code, data and services) when we need to run code that cannot be made
 * open source, we can run that code over a socket based connection in a design
 * pattern demonstrated in Java's RMI, (Remote Method Invocation). In our case,
 * we will call this collection of classes, (and interfaces) RSI, (which is
 * short for Remote Services Invocation). The idea is simple and the solution
 * will focus on remaining simple. Such that each intended class/interface will
 * focus on doing jus tone thing. This is in line with the original philosophy
 * of Unix, Linux, C & C++.
 *
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */

#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/requests.hpp>

#endif  // _EXTRA_RSI_HPP