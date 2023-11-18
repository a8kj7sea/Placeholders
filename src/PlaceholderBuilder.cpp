#include <iostream>
#include <map>
#include <string>

#include "PlaceholderLoader.cpp"

using namespace std;

class PlaceholderBuilder {
 private:
  string rawStr;

 public:
  map<string, string> loadedPlaceholdersMap
  PlaceholderBuidler(string inputString) {
    this->rawStr = inputString;
    PlaceholderLoader placeholderLoaderObject;

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