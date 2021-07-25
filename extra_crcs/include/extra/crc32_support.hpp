#ifndef _EXTRA_CRC32_SUPPORT_HPP
#define _EXTRA_CRC32_SUPPORT_HPP

#include <iostream>
#include <stdint.h>
#include <stdio.h>

//
// simplest crc32 c++ implementation
// https://gist.github.com/timepp
//

class crc32 {

public:
  crc32(const char *randomString = "default seed");
  uint32_t update(const std::string &str);

private:
  static void generate_table(uint32_t (&table)[256]);
  static uint32_t update(uint32_t (&table)[256], uint32_t initial,
                         const void *buf, size_t len);
  static uint32_t update(uint32_t (&table)[256], uint32_t initial,
                         const std::string &str);

  static uint32_t table[256];
  static uint32_t initial;
};

class Crc32CollisionException : public std::exception {
public:
  virtual char const *what() const noexcept {
    return "Crc32CollisionException";
  }
};

// usage: the following code generates crc for 2 pieces of data
// uint32_t table[256];
// crc32::generate_table(table);
// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
// crc = crc32::update(table, crc, data_piece2, len2);
// output(crc);

//
// 32bit CRC COLLISIONS
//
// crc32 _crc;
//
//     cout <<
//     _crc.update("r1bq1rk1/2p1bppp/p2p1n2/np2p3/4P3/1BPP1N2/PP3PPP/RNBQR1K")
//     << endl; cout <<
//     _crc.update("2r2k2/p2bpp2/3p2p1/1pr4p/4PN1P/1P3P2/P1PR2P1/1K2R") << endl;
//
//  With only perhaps a 100,000 to 200,000 entries (if that), we managed to beat
//  1 chance in 4.2 billion with the above two strings.
//

#endif // _EXTRA_CRC32_SUPPORT_HPP
