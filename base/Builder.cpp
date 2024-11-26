#include "../headers/Builder.h"
#include "../headers/Loader.h"
#include "../headers/StringUtils.h"
#include <iostream>

/**
 * @file Builder.cpp
 * @brief Implementation of the Builder class for processing and replacing placeholders in strings.
 */

using namespace std;

/**
 * @brief Constructs a Builder object and initializes it with a raw input string.
 *        Loads placeholders from a specified file and stores them in a map.
 *
 * @param input_string The raw input string containing placeholders.
 */
Builder::Builder(string input_string)
{
    this->raw_string = input_string;
    Loader placeholder_loader("../files/placeholders.txt");

    placeholder_loader.load();
    loaded_placeholders = placeholder_loader.placeholders_map;
}

/**
 * @brief Processes the raw string and replaces placeholders with their corresponding values.
 *
 * @return The processed string with placeholders replaced, or an empty string if the raw string is empty.
 */
string Builder::build()
{
    if (raw_string.empty())
        return "";

    // Iterate over each placeholder and perform the replacement
    for (const auto &entry : loaded_placeholders)
    {
        string placeholder = entry.first;
        string replacement = entry.second;

        size_t position = 0; // Start at the beginning of the string
        // Loop until all occurrences of the placeholder are replaced
        while ((position = raw_string.find(placeholder, position)) != string::npos)
        {
            raw_string.replace(position, placeholder.length(), replacement);
            position += replacement.length();  // Move past the replacement
        }
    }

    return raw_string;
}
