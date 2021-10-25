#include "extras/sockets/Domains.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/string_support.hpp"

using namespace std;

namespace extras {

  IPAddress Domain::resolve(const DomainName &domainName) const {
    string filename = "/tmp/out.txt";
    string cmd = "ping -c 1 " + domainName + " >" + filename;
    system(cmd.c_str());
    ifstream out(filename);
    string line1;
    getline(out, line1);
    DomainException::assertion(line1, domainName);
    auto parts = extras::split(line1, '(');
    auto parts2 = extras::split(parts[1], ')');
    return parts2[0];
  }

  void DomainException::assertion(const std::string &response,
                                  const DomainName &name) {
    string msg = "Name or service not known";
    if (response.length() == 0 || extras::contains(response, msg))
      throw DomainException((msg + ": " + name).c_str(), __INFO__);
  }

}  // namespace extras
