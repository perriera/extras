#include <extras/sockets/CSocketClient.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const* argv[]) {
  try {
    CSocketClient client(argv[1], PORT);
    client.connect();
    stringstream ss;
    ss << "Hello from CSocketClient" << endl;
    client.send(ss.str());
    string msg = client.read();
    cout << msg << endl;
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}
