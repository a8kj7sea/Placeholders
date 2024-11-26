#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <map>
#include <vector>

/**
 * @file Loader.h
 * @brief Header file for the Loader class to load and parse placeholders from a file.
 */

using namespace std;

/**
 * @class Loader
 * @brief A class to load placeholders from a file and store them in a map.
 */
class Loader {
 private:
  string placeholders_file_path;

 public:
  map<string, string> placeholders_map;

  Loader();
  Loader(string path);

  string getPlaceholdersFilePath();

  void load();
};

#endif
