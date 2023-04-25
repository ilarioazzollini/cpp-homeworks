#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

int main() {
  std::string input{};
  std::string delimiter = " ";
  std::vector<std::string> result{};

  std::cout << "Example program that splits strings." << std::endl;
  std::cout << "Please enter a string:" << std::endl;
  std::getline(std::cin, input);

  result = no_strings_attached::Split(input, delimiter);

  std::cout << "Your split string: ";
  for (const auto &string : result) {
    std::cout << "'" << string << "' ";
  }
  std::cout << "" << std::endl;

  return 0;
}
