#include <iostream>
#include <string>

#include <no_strings_attached/string_trim.h>

int main() {
  std::string input{};
  std::string result{};

  std::cout << "Example program that trims strings." << std::endl;
  std::cout << "Please enter a string:" << std::endl;
  std::getline(std::cin, input);

  result = no_strings_attached::string_trim::Trim(input);

  std::cout << "Your trimmed string: '" << result << "'" << std::endl;

  return 0;
}
