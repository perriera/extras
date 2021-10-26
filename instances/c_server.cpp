#include <extras/sockets/CSocketServer.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const*[]) {
  try {
    CSocketServer server(PORT);
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
