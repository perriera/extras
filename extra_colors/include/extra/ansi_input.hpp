#ifndef _ANSI_INPUT_HPP
#define _ANSI_INPUT_HPP

#include "extra/keywords.hpp"
#include <iostream>

//
// simplest ansi color c++ implementation
// https://www.tutorialspoint.com/Read-a-character-from-standard-input-without-waiting-for-a-newline-in-Cplusplus
//

interface ansi_input {
  const char *read();
};

  // cout << reset << endl;
  // system("stty raw");
  // char c = ' ';
  // while (c != 'x') {
  //     c = getchar();
  //     cout << c;
  // }
  //     system("stty sane");

#endif // _ANSI_INPUT_HPP
