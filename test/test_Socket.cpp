#include <cstdint>
#include <extras/paths.hpp>
#include <extras/strings.hpp>

#include "catch.hpp"
#include "extras/sockets/Socket.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify SocketInterface socket()", "[SocketInterface]") {
  string hostname = "localhost";
  int port = 8000;
  Socket socket(hostname, port);
}

SCENARIO("Verify SocketInterface connect()", "[SocketInterface]") {
  string hostname = "localhost";
  int port = 8000;
  Socket socket(hostname, port);
  system("build/server &");
  socket.connect();
}

SCENARIO("Verify SocketInterface send()", "[SocketInterface]") {
  string hostname = "localhost";
  int port = 8000;
  Socket socket(hostname, port);
  system("build/server &");
  socket.connect();
  socket.send("hello from client");
}
