#ifndef _CUSTOMER_HPP
#define _CUSTOMER_HPP

#include "extra/Definitions.hpp"
#include <iostream>
#include <map>

//
// Customer table
//
typedef long CustomerKey;

struct Customer {

  CustomerKey key;
  std::string name;
  std::string address;
  long checkinDate;
};

typedef std::map<CustomerKey, Customer> CustomerTable;

#endif // _CUSTOMER_HPP
