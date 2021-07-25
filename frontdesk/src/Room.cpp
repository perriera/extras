#include "../frontdesk/include//Room.hpp"
#include "extra/string_support.hpp"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &out, const Room &) {
  // out << obj._parameters << endl;
  // out << obj._moves << endl;
  return out;
}

istream &operator>>(istream &in, Room &) { return in; }