#ifndef _HELLOWORLD_HPP
#define _HELLOWORLD_HPP

#include <iostream>

#include "extra/Definitions.hpp"

interface HelloWorldInterface {
  virtual std::string say_hello() const pure;
};

class HelloWorld implements HelloWorldInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _HELLOWORLD_HPP
