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

#include <cstdint>
#include <extras/crcs/crc64_support.hpp>
#include <string>

namespace extras {

  // simplest crc64 c++ implementation
  // https://gist.github.com/timepp
  void crc64::generate_table(std::uint64_t (&table)[256]) {
    for (int i = 0; i < 256; ++i) {
      std::uint64_t crc = i;

      for (std::uint8_t j = 0; j < 8; ++j) {
        // is current coefficient set?
        if (crc & 1) {
          // yes, then assume it gets zero'd (by implied x^64 coefficient of
          // dividend)
          crc >>= 1;

          // and add rest of the divisor
          crc ^= initial;
        } else {
          // no? then move to next coefficient
          crc >>= 1;
        }

        table[i] = crc;
      }
    }
  }

  std::uint64_t crc64::update(std::uint64_t (&table)[256],
                              std::uint64_t /*initial*/,
                              const std::uint8_t *buf, std::size_t len) {
    std::uint64_t crc = 0;

    for (std::size_t i = 0; i < len; ++i) {
      std::uint8_t index = buf[i] ^ crc;
      std::uint64_t lookup = table[index];

      crc >>= 8;
      crc ^= lookup;
    }

    return crc;
  }

  // uint64_t crc64::update(const unsigned char *buf, size_t len) {
  //   return update(table, crc64::initial, buf, len);
  // }

  std::uint64_t crc64::update(std::uint64_t (&table)[256],
                              std::uint64_t initial, const std::string &str) {
    return update(table, initial, (const std::uint8_t *)str.c_str(),
                  str.length());
  }

  std::uint64_t crc64::update(const std::string &str) {
    return update(table, crc64::initial, (const std::uint8_t *)str.c_str(),
                  str.length());
  }

  std::uint32_t crc64::update(const byte *buffer, int len) {
    return update(table, crc64::initial, buffer, len);
  }

  // uint64_t poly = 0xC96C5795D7870F42;
  // uint64_t table[256];

  std::uint64_t crc64::table[256];
  std::uint64_t crc64::initial = 0xC96C5795D7870F42;
  crc64 default_crc64;

  crc64::crc64(const char * /*randomString*/) {
    crc64::generate_table(crc64::table);
    // crc64::initial = crc64::update(table, 0, randomString);
  }
}  // namespace extras
