#include <iostream>
#include <string>

#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {
std::string Trim(const std::string &str, char char_to_trim, Side side) {
  std::string current_result{};
  std::string next_result{};
  bool falling_through = false;

  current_result = str;
  std::string::size_type current_length = current_result.size();

  if (current_result.empty()) {
    return current_result;
  }

  switch (side) {

  case Side::kBoth:
    falling_through = true;
    [[fallthrough]];

  case Side::kLeft:
    while (current_result.find(char_to_trim, 0) == 0) {
      next_result = current_result.substr(1);

      // // Debug
      // std::cout << "current_result: '" << current_result << "'" << std::endl;
      // std::cout << "next_result: '" << next_result << "'\n" << std::endl;
      // // Debug

      current_result = next_result;
      current_length = current_result.size();

      if (current_result.empty()) {
        break;
      }
    }
    if (falling_through) {
      [[fallthrough]];
    }
    else {
      break;
    }

  case Side::kRight:
    while (current_result.find(char_to_trim, current_length - 1) == current_length - 1) {
      next_result = current_result.substr(0, current_length - 1);

      // // Debug
      // std::cout << "current_result: '" << current_result << "'" << std::endl;
      // std::cout << "next_result: '" << next_result << "'\n" << std::endl;
      // // Debug

      current_result = next_result;
      current_length = current_result.size();

      if (current_result.empty()) {
        break;
      }
    }
    break;

  }
  return current_result;
}
std::string Trim(const std::string &str) {
  std::string result{};
  char char_to_trim = ' ';

  result = Trim(str, char_to_trim, Side::kBoth);

  return result;
}
} // namespace no_strings_attached
