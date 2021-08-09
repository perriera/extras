#ifndef _EXTRA_VERSION_HPP
#define _EXTRA_VERSION_HPP
/**
 * @file version.hpp
 * @author Matt Williams (mattltf@protonmail.com)
 * @brief Adds version support for Cmake script
 * @version 3.2.0
 * @date 2021-08-08
 *
 * @copyright Copyright (c) 2021 Perry Anderson, Matt Williams
 * All Rights Reserved, MIT License.
 */

#define EXTRAS_VER_MAJOR 3
#define EXTRAS_VER_MINOR 2
#define EXTRAS_VER_PATCH 0

#define SPDLOG_VERSION \
  (EXTRAS_VER_MAJOR * 10000 + EXTRAS_VER_MINOR * 100 + EXTRAS_VER_PATCH)

#endif  // _EXTRA_VERSION_HPP