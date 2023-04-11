#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

  using std::string_literals::operator""s;
  std::string fortune_telling{};

  const std::map<std::string, std::string> noun{
      {"spring", "STL guru"},
      {"summer", "C++ expert"},
      {"autumn", "coding beast"},
      {"winter", "software design hero"}};

  std::array<std::string, 3UL> ending{"eats UB for breakfast",
                                      "finds errors quicker than the compiler",
                                      "is not afraid of C++ error messages"};

  std::cout << "Welcome to the fortune teller program!" << std::endl;

  std::string input_name{};
  std::cout << "Please enter your name:" << std::endl;
  std::cin >> input_name;

  std::string season{};
  std::cout << "Please enter the time of year when you were born:\n(pick from "
               "'spring', 'summer', 'autumn', 'winter')"
            << std::endl;
  std::cin >> season;

  std::vector<std::string> adjectives;

  {
    std::string current_adjective{};

    std::cout << "Please enter an adjective:" << std::endl;
    std::cin >> current_adjective;
    adjectives.emplace_back(current_adjective);

    std::cout << "Please enter another adjective:" << std::endl;
    std::cin >> current_adjective;
    adjectives.emplace_back(current_adjective);
  } // current_adjective goes out of scope and we free the memory

  int adjectives_index = input_name.size() % adjectives.size();
  int ending_index = input_name.size() % ending.size();

  fortune_telling = "\n"s + "Here is your description:"s + "\n"s + input_name +
                    ", the "s + adjectives[adjectives_index] + " "s +
                    noun.at(season) + " that "s + ending[ending_index];

  std::cout << fortune_telling << std::endl;
}