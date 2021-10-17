#include <cstdint>
#include <extras/paths.hpp>
#include <extras/strings.hpp>

#include "catch.hpp"
#include "extras/sockets/SocketClient.hpp"

using namespace std;
using namespace extras;

// SCENARIO("Verify SocketInterface socket()", "[SocketInterface]") {
//   string hostname = "localhost";
//   int port = 8000;
//   SocketClient socket(hostname, port);
// }

// SCENARIO("Verify SocketInterface connect()", "[SocketInterface]") {
//   string hostname = "localhost";
//   int port = 8000;
//   SocketClient socket(hostname, port);
//   system("build/server &");
//   socket.connect();
// }

// SCENARIO("Verify SocketInterface send()", "[SocketInterface]") {
//   string hostname = "localhost";
//   int port = 8000;
//   SocketClient socket(hostname, port);
//   system("build/server &");
//   socket.connect();
//   socket.send("hello from client");
// }

// SCENARIO("Verify SocketInterface read()", "[SocketInterface]") {
//   string hostname = "localhost";
//   int port = 8000;
//   SocketClient socket(hostname, port);
//   system("build/server &");
//   socket.connect();
//   socket.send("hello from client");
//   socket.read();
//   string msg = socket;
//   cout << msg << endl;
//   REQUIRE(msg == "Hello from server");
// }

SCENARIO("Verify SocketInterface socket_server", "[SocketInterfaceX]") {
  string hostname = "localhost";
  int port = 8000;
  SocketClient socket(hostname, port);
  system("build/socket_server &");
  socket.connect();
  socket.send("hello from SocketClient");
  socket.read();
  string msg = socket;
  cout << msg << endl;
  REQUIRE(msg == "Hello from SocketServer");
}
