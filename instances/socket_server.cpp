#include <iostream>

#include "extras/sockets/SocketServer.hpp"

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const*[]) {
  try {
    SocketServer server(PORT);
    server.accept();
    string msg = server.read();
    cout << msg << endl;
    server.send("Hello from SocketServer");
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}
