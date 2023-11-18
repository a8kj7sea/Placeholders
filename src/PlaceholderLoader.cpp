#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "utils/StringUtils.cpp"

using namespace std;

class PlaceholderLoader {
 private:
  string placeholdersFilePath;

 public:
  map<string, string> placeholdersMap;

  PlaceholderLoader(string path) { this->placeholdersFilePath = path; }

  string getPlaceholdersFilePath() { return placeholdersFilePath; }

  void load() {
    StringUtils strUtils;
    ifstream inputFile(placeholdersFilePath);

    if (!inputFile.is_open()) {
      cerr << "Unable to open file: " << placeholdersFilePath << "\n";
      return;
    }

    string line;
    vector<string> lines;
    while (getline(inputFile, line)) {
      lines = strUtils.splitString(line, '=');
      placeholdersMap.insert(make_pair(lines[0], lines[1]));
    }
    inputFile.close();
  }
};
