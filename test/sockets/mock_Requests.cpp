
// #include <iostream>

// #include "../vendor/catch.hpp"
// #include "../vendor/fakeit.hpp"
// #include "extras/sockets/Requests.hpp"

// //
// // https://github.com/eranpeer/FakeIt/wiki/Quickstart
// //

// using namespace extras;
// using namespace fakeit;

// /**
//  * @brief PortAuthorityInterface
//  * @ref https://eval.atlassian.net/browse/PE-16
//  *
//  * GIVEN we need to anticipate many requests to the a sockets based server
//  WHEN
//  * we use a centralized port for the purposes of just allocating available
//  * socket ports THEN we can service many socket server requests from the same
//  * linux box, (local, Internet, VPN or otherwise)
//  *
//  */

// SCENARIO("Mock PortAuthorityInterface", "[PortAuthorityInterface]") {
//   int correct_request = 9000;
//   Mock<PortAuthorityInterface> mock;
//   When(Method(mock, request)).Return(correct_request);

//   PortAuthorityInterface &i = mock.get();
//   REQUIRE(i.request() == correct_request);
//   Verify(Method(mock, request));
// }
