#include <extras/sockets/SocketClient.hpp>
#include <iostream>

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const*[]) {
  try {
    SocketClient client("localhost", PORT);
    client.connect();
    client.send("Hello from SocketClient");
    string msg = client.read();
    cout << msg << endl;
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}
