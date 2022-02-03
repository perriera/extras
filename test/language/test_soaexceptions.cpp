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
  extras::WhereAmI _whereAmI;

 public:
  SOAException(const std::string& msg, const extras::WhereAmI& whereAmI)
      : _msg(msg), _whereAmI(whereAmI) {}
  virtual const char* what() const noexcept { return _msg.c_str(); }
};

// =============================================================
// extras::SpecificCustomException: Port: a<b wasn't found
// -------------------------------------------------------------
// /home/perry/Projects/extras/test/language/test_exceptions.cpp
// void ____C_A_T_C_H____T_E_S_T____12(): line 140
// =============================================================

class SoaOnDemandClientInitializedException : public SOAException {
 public:
  SoaOnDemandClientInitializedException(const extras::WhereAmI& ref)
      : SOAException("SoaOnDemandClientInitializedException", ref) {}

  static void assertion(bool alreadySetup, const extras::WhereAmI& ref) {
    if (alreadySetup) throw SoaOnDemandClientInitializedException(ref);
  }
};

using namespace std;
using namespace extras;

class SoaOnDemandClient {
  bool _initialized = false;

 public:
  bool isInitialized() const noexcept { return _initialized; }
  void initialize(const std::string&) {
    if (isInitialized()) return;
  }
};

SCENARIO("Test SOAException", "[soa_exceptions_testcases]") {
  try {
    throw SOAException("this is a test", __INFO__);
  } catch (SOAException& ex) {
    SUCCEED(ex.what());
  } catch (std::exception& ex) {
    FAIL(ex.what());
  }
}

SCENARIO("Test SOAException2", "[soa_exceptions_testcases]") {
  try {
    throw SoaOnDemandClientInitializedException(__INFO__);
  } catch (SOAException& ex) {
    cout << ex.what() << endl;
    SUCCEED(ex.what());
  } catch (std::exception& ex) {
    FAIL(ex.what());
  }
}
