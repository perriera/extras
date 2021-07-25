#include <iostream>
#include "extra/string_support.hpp"

using namespace std;

deque<string> split(const string &s, char delim)
{
  deque<string> result;
  stringstream ss(s);
  string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

string replace_all(const string &s, char a, char b)
{
  string dup = s;
  replace(dup.begin(), dup.end(), a, b);
  return dup;
}

string remove_all(const string &s, char a)
{
  string dup = s;
  dup.erase(std::remove(dup.begin(), dup.end(), a), dup.end());
  return dup;
}

string replace_all(string str, const string &from, const string &to)
{
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();// Handles case where 'to' is a substring of 'from'
  }
  return str;
}
