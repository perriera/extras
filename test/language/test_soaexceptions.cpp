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

#include <extras/exceptions.hpp>
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/strings.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock ExceptionInterface
 *
 * We need to provide additional information for loggers
 * as well as to streamline the custom exception process
 * for supported applications.
 *
 */

class SOAException : public std::exception {
  std::string _msg;

 public:
  SOAException(const std::string& msg) : _msg(msg) {}
  virtual const char* what() const noexcept { return _msg.c_str(); }
  virtual std::string getwhat() const noexcept {
    auto mangled = typeid(*this).name();
    auto ptr = std::unique_ptr<char, decltype(&std::free)>{
        abi::__cxa_demangle(mangled, nullptr, nullptr, nullptr), std::free};
    return {ptr.get()};
  };
};

class SoaOnDemandClientInitializedException : public SOAException {
 public:
  SoaOnDemandClientInitializedException()
      : SOAException("SoaOnDemandClientInitializedException") {}
};

using namespace std;
using namespace extras;

class SoaOnDemandClient {
  bool _initialized = false;

 public:
  bool isInitialized() const noexcept { return _initialized; }
  void initialize(const std::string& soaService) {
    if (isInitialized()) return;
  }
};

SCENARIO("Test SOAException", "[soa_exceptions_testcases]") {
  try {
    throw SOAException("this is a test");
  } catch (SOAException& ex) {
    SUCCEED(ex.what());
  } catch (std::exception& ex) {
    FAIL(ex.what());
  }
}

SCENARIO("Test SOAException2", "[soa_exceptions_testcases]") {
  try {
    throw SoaOnDemandClientInitializedException();
  } catch (SOAException& ex) {
    cout << ex.what() << endl;
    SUCCEED(ex.what());
  } catch (std::exception& ex) {
    FAIL(ex.what());
  }
}
