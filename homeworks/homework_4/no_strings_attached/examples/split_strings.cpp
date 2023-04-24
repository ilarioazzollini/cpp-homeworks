#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

int main() {
  std::string const input_string = "is string This is a string";

  std::cout << "\nFirst Test" << std::endl;
  std::string const delimiter1 = "zz";
  std::vector<std::string> result1;
  result1 = no_strings_attached::string_split::Split(input_string, delimiter1);

  std::cout << "\nSecond Test" << std::endl;
  std::string const delimiter2 = "is";
  std::vector<std::string> result2;
  result2 = no_strings_attached::string_split::Split(input_string, delimiter2);

  for (const auto &string : result2) {
    std::cout << "'" << string << "'" << std::endl;
  }

  std::cout << "\nSecond Test" << std::endl;
  std::string const delimiter3 = "is";
  std::vector<std::string> result3;
  result3 = no_strings_attached::string_split::Split(input_string, delimiter3, 2);

  for (const auto &string : result3) {
    std::cout << "'" << string << "'" << std::endl;
  }

  return 0;
}
