#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

// https://en.cppreference.com/w/cpp/string/basic_string/find

namespace no_strings_attached {
namespace string_split {
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter) {
  std::vector<std::string> result;
  std::string::size_type n;
  std::string::size_type current_pos{0};
  std::string::size_type delimiter_length = delimiter.size();

  n = str.find(delimiter, current_pos);
  result.emplace_back(str.substr(current_pos, n - current_pos));

  // Debug
  std::cout << "current pos: " << current_pos << std::endl;
  std::cout << "current n: " << n << std::endl;
  std::cout << "current substring: " << str.substr(current_pos, n - current_pos)
            << std::endl;
  // Debug

  while (n != std::string::npos) {
    current_pos = n + delimiter_length;
    n = str.find(delimiter, current_pos);
    std::cout << str.substr(current_pos, current_pos - n) << std::endl;
    result.emplace_back(str.substr(current_pos, n - current_pos));

    // Debug
    std::cout << "current pos: " << current_pos << std::endl;
    std::cout << "current n: " << n << std::endl;
    std::cout << "current substring: "
              << str.substr(current_pos, n - current_pos) << std::endl;
    // Debug
  }

  return result;
}
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter,
                               int number_of_chunks_to_keep) {
  std::vector<std::string> result;
  result = Split(str, delimiter);

  while (number_of_chunks_to_keep < result.size()) {
    result.pop_back();
  }

  return result;
}
} // namespace string_split
} // namespace no_strings_attached