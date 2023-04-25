#include <string>

#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {
namespace string_trim {
std::string Trim(const std::string &str, char char_to_trim, Side side) {
  std::string result{};
  std::string::size_type str_length = str.size();
  switch (side) {
  case Side::kLeft:
    if (str.find(char_to_trim, 0) == 0) {
      result = str.substr(1);
    }
    else {
      result = str;
    }
    break;

  case Side::kRight:
    if (str.find(char_to_trim, str_length - 1) == str_length - 1) {
      result = str.substr(0, str_length - 1);
    }
    else {
      result = str;
    }
    break;

  case Side::kBoth:
    if ((str.find(char_to_trim, 0) == 0) && (str.find(char_to_trim, str_length - 1) == (str_length - 1))) {
      result = str.substr(1, str_length - 2);
    }
    else {
      result = str;
    }
    break;
  }
  return result;
}
std::string Trim(const std::string &str) {
  std::string result{};
  char char_to_trim = ' ';
  Side side = Side::kBoth;

  result = Trim(str, char_to_trim, side);

  return result;
}
} // namespace string_trim
} // namespace no_strings_attached