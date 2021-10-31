#include <extras/sockets/SocketClient.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const* argv[]) {
  try {
    SocketClient client(argv[1], PORT);
    client.connect();
    stringstream ss;
    ss << "Hello from SocketClient" << endl;
    client.send(ss.str());
    string msg = client.read();
    cout << msg << endl;
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}