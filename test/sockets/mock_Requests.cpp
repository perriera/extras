
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/Requests.hpp"

using namespace extras;
using namespace fakeit;
using namespace std;

SCENARIO("Mock RequestsInterface", "[RequestsInterface]") {
  std::string correct_request = "upload";
  int correct_server = 8080;
  int correct_response = 9000;
  Mock<RequestsInterface> mock;
  When(Method(mock, request)).Return(correct_response);

  RequestsInterface &i = mock.get();
  REQUIRE(i.request(correct_request, correct_server) == correct_response);
  Verify(Method(mock, request));
}
