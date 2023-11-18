#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StringUtils {
  StringUtils() { cout << "Utils class\n"; }

 public:
  vector<string> splitString(const string& inputString, char delimiter) {
    istringstream iss(inputString);
    string token;
    vector<string> tokens;

    while (getline(iss, token, delimiter)) {
      tokens.push_back(token);
    }

    return tokens;
  }
};