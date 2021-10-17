#include <iostream>

#include "extras/sockets/SocketServer.hpp"

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const*[]) {
  SocketServer server(PORT);
  server.accept();
  server.read();
  string msg = server;
  cout << "HELLO JESUS " << msg << endl;
  server.send("Hello from SocketServer");
}
