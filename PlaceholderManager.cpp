#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StringUtils {
 public:
  StringUtils() { cout << "Utils class\n"; }
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

class PlaceholderLoader {
 private:
  string placeholdersFilePath;

 public:
  map<string, string> placeholdersMap;

  PlaceholderLoader() {}
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

class PlaceholderBuilder {
 private:
  string rawStr;

 public:
  map<string, string> loadedPlaceholdersMap;

  PlaceholderBuilder(string inputString) {
    this->rawStr = inputString;
    PlaceholderLoader placeholderLoaderObject("placeholders.txt");

    placeholderLoaderObject.load();
    loadedPlaceholdersMap = placeholderLoaderObject.placeholdersMap;
  }

  string build() {
    if (rawStr.length() == 0 || rawStr == "") return NULL;

    for (const auto& element : loadedPlaceholdersMap) {
      string key = element.first;
      string value = element.second;

      if (rawStr.find(key) != string::npos) {
        size_t pos = rawStr.find(key);
        rawStr.replace(pos, key.length(), value);
      }
    }

    return rawStr;
  }
};

int main() {
  string text = "Simple Example by %author%";

  PlaceholderBuilder builder(text);

  cout << "before : \n" << text << "\n";

  cout << "after : \n" << builder.build() << "\n";

  int x;

  cout << "Press any key to close program !\n";

  cin >> x;

  return 0;
}
