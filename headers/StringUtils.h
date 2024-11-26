#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

/**
 * @class StringUtils
 * @brief A utility class for string manipulation functions.
 * 
 * This class provides methods for common string operations, such as splitting
 * a string into substrings based on a specified delimiter.
 */
class StringUtils
{
public:
    /**
     * @brief Default constructor for the StringUtils class.
     */
    StringUtils();

    /**
     * @brief Splits a string into a vector of substrings based on a delimiter.
     * 
     * This method takes a string and a delimiter character, and returns a vector
     * containing the substrings that are separated by the delimiter in the input string.
     * 
     * @param inputString The string to be split.
     * @param delimiter The character used to split the string.
     * 
     * @return A vector of strings that were separated by the delimiter in the input string.
     */
    vector<string> splitString(const string &inputString, char delimiter);
};

#endif
