#include <extras/sockets/CSocketServer.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace extras;

#define PORT 8001
int main(int argc, char const* argv[]) {
  if (argc < 2) {
    printf("need an ip\n");
    return -1;
  }
  try {
    CSocketServer server(argv[1], PORT);
    server.accept();
    string msg = server.read();
    cout << msg << endl;
    stringstream ss;
    ss << "Hello from CSocketServer" << endl;
    server.send(ss.str());
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}
