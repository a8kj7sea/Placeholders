
#include <sstream>
#include <iostream>

#include "../../headers/StringUtils.h"


/**
 * @file StringUtils.cpp
 * @brief Implementation of utility functions for string manipulation.
 */

using namespace std;

/**
 * @brief Constructor for StringUtils class.
 *        Displays a message when the class is instantiated.
 */
StringUtils::StringUtils()
{
    cout << "StringUtils class instantiated.\n";
}

/**
 * @brief Splits a string into a vector of substrings based on the given delimiter.
 *
 * @param input_string The string to be split.
 * @param delimiter The character used to split the string.
 * @return A vector of substrings obtained by splitting the input string.
 */
vector<string> StringUtils::splitString(const string &input_string, char delimiter)
{
    istringstream stream(input_string);
    string segment;
    vector<string> segments;

    while (getline(stream, segment, delimiter))
    {
        segments.push_back(segment);
    }

    return segments;
}
