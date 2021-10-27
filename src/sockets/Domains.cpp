#include "extras/sockets/Domains.hpp"

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/strings/string_support.hpp"

using namespace std;

namespace extras {

  IPAddress Domain::resolve() const {
    DomainException::assertion(*this);
    string filename = "/tmp/out.txt";
    string cmd = "ping -c 1 " + _domainname + " >" + filename;
    system(cmd.c_str());
    ifstream out(filename);
    string line1;
    getline(out, line1);
    DomainException::assertion(line1, _domainname);
    auto parts = extras::split(line1, '(');
    auto parts2 = extras::split(parts[1], ')');
    return parts2[0];
  }

  bool Domain::exists() const {
    struct hostent *ghbn =
        gethostbyname(_domainname.c_str());  // change the domain name
    return ghbn != nullptr;
  }

  void DomainException::assertion(const Domain &domain) {
    string msg = "Name or service not known";
    if (!domain.exists())
      throw DomainException((msg + ": " + domain.name()).c_str(), __INFO__);
  }

  void DomainException::assertion(const std::string &response,
                                  const DomainName &name) {
    string msg = "Name or service not known";
    if (response.length() == 0 || extras::contains(response, msg))
      throw DomainException((msg + ": " + name).c_str(), __INFO__);
  }

}  // namespace extras
