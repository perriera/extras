#include <extras/crc32_support.hpp>
#include <extras/crc64_support.hpp>
#include <extras/string_support.hpp>
#include <fstream>
#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

struct SomeInterface {
  virtual int foo(int) = 0;
  virtual int bar(int, int) = 0;
};

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace std;
using namespace fakeit;

SCENARIO("Verify FakeIt: Stubbing", "[FakeIt]") {
  Mock<SomeInterface> mock;
  // Stub a method to return a value once
  When(Method(mock, foo)).Return(1);

  // Stub multiple return values (The next two lines do exactly the same)
  When(Method(mock, foo)).Return(1, 2, 3);
  When(Method(mock, foo)).Return(1).Return(2).Return(3);

  // Return the same value many times (56 in this example)
  When(Method(mock, foo)).Return(56_Times(1));

  // Return many values many times (First 100 calls will return 1, next 200
  // calls will return 2)
  When(Method(mock, foo)).Return(100_Times(1), 200_Times(2));

  // Always return a value (The next two lines do exactly the same)
  When(Method(mock, foo)).AlwaysReturn(1);
  Method(mock, foo) = 1;
}

SCENARIO("Verify FakeIt: more specific", "[FakeIt]") {
  Mock<SomeInterface> mock;
  // Stub foo(1) to return the value '100' once (The next two lines do the same)
  When(Method(mock, foo).Using(1)).Return(100);
  When(Method(mock, foo)(1)).Return(100);

  // Stub 'foo(1)' to always return '100'. For all other calls always return 0.
  When(Method(mock, foo))
      .AlwaysReturn(0);  // Any invocation of foo will return 0
  When(Method(mock, foo).Using(1))
      .AlwaysReturn(100);  // override only for 'foo(1)'

  // The next two lines do exactly the same
  When(Method(mock, foo).Using(1)).AlwaysReturn(0);
  Method(mock, foo).Using(1) = 0;
}

SCENARIO("Verify FakeIt: exceptions", "[FakeIt]") {
  Mock<SomeInterface> mock;
  // Stub foo(1) to return the value '100' once (The next two lines do the same)
  // Throw once
  When(Method(mock, foo)).Throw(exception());
  // Throw several times
  When(Method(mock, foo)).Throw(exception(), exception());
  // Throw many times
  When(Method(mock, foo)).Throw(23_Times(exception()));
  // Always throw
  When(Method(mock, foo)).AlwaysThrow(exception());
}
