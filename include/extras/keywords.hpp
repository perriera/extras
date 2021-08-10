#ifndef _EXTRA_KEYWORDS_HPP
#define _EXTRA_KEYWORDS_HPP

/**
 * @file keywords.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Adds extra keywords for C++ applications
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */

namespace extras
{

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

}

#include "extra/interfaces.hpp"

#endif // _EXTRA_KEYWORDS_HPP