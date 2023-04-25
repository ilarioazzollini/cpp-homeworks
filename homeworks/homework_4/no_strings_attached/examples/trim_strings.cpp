#include <iostream>
#include <string>

#include <no_strings_attached/string_trim.h>

int main() {
  std::string result1 = no_strings_attached::string_trim::Trim(" hello ", ' ', Side::kLeft);
  std::cout << "'" << result1 << "'" << std::endl;

  std::string result2 = no_strings_attached::string_trim::Trim(" hello ", ' ', Side::kRight);
  std::cout << "'" << result2 << "'" << std::endl;

  std::string result3 = no_strings_attached::string_trim::Trim(" hello ", ' ', Side::kBoth);
  std::cout << "'" << result3 << "'" << std::endl;

  std::string input{};
  std::string result{};

  std::cout << "Example program that trims strings." << std::endl;
  std::cout << "Please enter a string:" << std::endl;
  std::getline(std::cin, input);

  result = no_strings_attached::string_trim::Trim(input);

  std::cout << "Your trimmed string: '" << result << "'" << std::endl;

  return 0;
}
