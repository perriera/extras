/**
 * @file types.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief C++ defined type definitions specific to this package
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXTRA_TYPES_HPP
#define _EXTRA_TYPES_HPP

/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * (See LICENSE.md for complete details)
 *
 */

/**
 * @file keywords.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Adds extra keywords for C++ applications
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

namespace extras {

  /**
   * @brief bytes
   *
   * " Of the same size as char, but guaranteed to be unsigned.
   *   Contains at least the [0, 255] range.[5] ""
   *    -- https://en.wikipedia.org/wiki/C_data_types
   *    -- Wikipedia, August 6, 2021
   *
   * [5]  ISO/IEC 9899:1999 specification, TC3 (PDF). p. 37,
   * § 6.2.6.1 Representations of types – General.
   *
   */

  using byte = unsigned char;
  using bytes = byte *;

  /**
   * @brief common types
   *
   * " Of the same size as char, but guaranteed to be unsigned.
   *   Contains at least the [0, 255] range.[5] ""
   *    -- https://en.wikipedia.org/wiki/C_data_types
   *    -- Wikipedia, August 6, 2021
   *
   * [5]  ISO/IEC 9899:1999 specification, TC3 (PDF). p. 37,
   * § 6.2.6.1 Representations of types – General.
   *
   */
  using Parameter = std::string;
  using Parameters = std::deque<Parameter>;
  using Filename = std::string;
  using Filenames = std::vector<Filename>;
  using Path = std::string;
  using Pathname = std::string;
  using Pathnames = std::vector<Filename>;

}  // namespace extras

#endif  // _EXTRA_TYPES_HPP