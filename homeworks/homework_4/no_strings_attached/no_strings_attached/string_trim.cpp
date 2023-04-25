#include <string>

#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {
std::string Trim(const std::string &str, char char_to_trim, Side side) {
  std::string result = str;
  std::string::size_type str_length = str.size();
  switch (side) {
  case Side::kBoth:
    if ((str.find(char_to_trim, 0) == 0) && (str.find(char_to_trim, str_length - 1) == (str_length - 1))) {
      result = str.substr(1, str_length - 2);
      break;
    }
    else {
      [[fallthrough]];
    }
  case Side::kLeft:
    if (str.find(char_to_trim, 0) == 0) {
      result = str.substr(1);
      break;
    }
    else {
      [[fallthrough]];
    }

  case Side::kRight:
    if (str.find(char_to_trim, str_length - 1) == str_length - 1) {
      result = str.substr(0, str_length - 1);
      break;
    }
    else {
      [[fallthrough]];
    }
    
  }
  return result;
}
std::string Trim(const std::string &str) {
  std::string previous_result{};
  std::string current_result{};
  char char_to_trim = ' ';

  previous_result = str;
  current_result = Trim(previous_result, char_to_trim, Side::kBoth);

  while (current_result != previous_result) {
    previous_result = current_result;
    current_result = Trim(previous_result, char_to_trim, Side::kBoth);
  }

  return current_result;
}
} // namespace no_strings_attached
