#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <map>

/**
 * @file Builder.h
 * @brief Header file for the Builder class, used for processing and replacing placeholders in strings.
 */

using namespace std;

/**
 * @class Builder
 * @brief A class to build and process strings by replacing placeholders with their corresponding values.
 */
class Builder {
 private:
  /**
   * @brief The raw input string containing placeholders.
   */
  string raw_string;

 public:
  /**
   * @brief A map containing loaded placeholders and their corresponding values.
   */
  map<string, string> loaded_placeholders;

  /**
   * @brief Constructs a Builder object and initializes it with a raw input string.
   * 
   * @param input_string The raw input string containing placeholders.
   */
  Builder(string input_string);

  /**
   * @brief Processes the raw string and replaces placeholders with their corresponding values.
   * 
   * @return The processed string with placeholders replaced.
   */
  string build();
};

#endif
