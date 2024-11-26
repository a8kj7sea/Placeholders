#include "../headers/Loader.h"
#include "../headers/StringUtils.h"
#include <fstream>
#include <iostream>

/**
 * @file Loader.cpp
 * @brief Implementation of the Loader class for loading and parsing placeholders from a file.
 */

using namespace std;

/**
 * @brief Default constructor for the Loader class.
 */
Loader::Loader() {}

/**
 * @brief Parameterized constructor for the Loader class.
 *        Sets the file path to load placeholders from.
 * 
 * @param path Path to the file containing placeholders.
 */
Loader::Loader(string path)
{
    this->placeholders_file_path = path;
}

/**
 * @brief Retrieves the file path of the placeholders file.
 * 
 * @return The file path as a string.
 */
string Loader::getPlaceholdersFilePath()
{
    return placeholders_file_path;
}

/**
 * @brief Loads placeholders from the specified file into a map.
 *        Splits each line by the '=' character and stores the key-value pairs.
 */
void Loader::load()
{
    StringUtils string_utils;
    ifstream input_file(placeholders_file_path);

    if (!input_file.is_open())
    {
        cerr << "Unable to open file: " << placeholders_file_path << "\n";
        return;
    }

    string line;
    vector<string> tokens;
    while (getline(input_file, line))
    {
        tokens = string_utils.splitString(line, '=');
        if (tokens.size() == 2)
        {
            placeholders_map.insert(make_pair(tokens[0], tokens[1]));
        }
        else
        {
            cerr << "Invalid placeholder format: " << line << "\n";
        }
    }
    input_file.close();
}
