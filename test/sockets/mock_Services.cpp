
// #include <iostream>

// #include "../vendor/catch.hpp"
// #include "../vendor/fakeit.hpp"
// #include "extras/sockets/Services.hpp"

// using namespace extras;
// using namespace fakeit;

// SCENARIO("Mock ServicesInterface", "[ServicesInterface]") {
//   std::string correct_request = "upload";
//   int correct_response = 9000;
//   Mock<ServicesInterface> mock;
//   When(Method(mock, request)).Return(correct_response);

//   ServicesInterface &i = mock.get();
//   REQUIRE(i.request(correct_request) == correct_response);
//   Verify(Method(mock, request));
// }
