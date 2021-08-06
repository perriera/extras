#ifndef _EXTRA_CRCS_HPP
#define _EXTRA_CRCS_HPP

/**
 * @file crcs.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Addes extra crc support for C++ applications
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */
#include "extra/crc16_support.hpp"
#include "extra/crc32_support.hpp"
#include "extra/crc64_support.hpp"
#include "extra/octal_support.hpp"
#include "extra/interfaces.hpp"

namespace extras
{

    /**
     * @brief interface CRCInterface
     * 
     * Basic interface for CRC calculations
     * 
     */
    using bytes = unsigned char;
    interface CRCInterface
    {

        /**
         * Sets up a bugger to have it's CRC caculated.
         * Size of calculation to be determined by implementation/
         */

        virtual const CRCInterface &calculate(const bytes &buffer, int len) pure;
        virtual const CRCInterface &calculate(const std::string &str) pure;
        virtual operator uint16_t() const pure;
        virtual operator uint32_t() const pure;
        virtual operator uint64_t() const pure;
    };

    /**
     * @brief class CRCInterface
     * 
     * Basic implementation for CRC calculations
     * 
     */

    concrete class CRCCalculator implements CRCInterface
    {
        std::string _str;
        const bytes *_buffer = nullptr;
        int _len = 0;

    public:
        virtual const CRCInterface &calculate(const bytes &buffer, int len)
        {
            this->_buffer = &buffer;
            this->_len = len;
            return *this;
        }
        virtual const CRCInterface &calculate(const std::string &str)
        {
            this->_str = str;
            return *this;
        };
        operator uint16_t() const;
        operator uint32_t() const;
        operator uint64_t() const;
    };

}

#endif // _EXTRA_CRCS_HPP
