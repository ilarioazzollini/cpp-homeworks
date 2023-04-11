#include <iostream>
#include <random>

int main() {
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};

  std::cout << "Welcome to the GUESSING GAME!\nI will generate a number and "
               "you will guess it!"
            << std::endl;

  int smallest_number{};
  std::cout << "Please provide the smallest number: " << std::endl;
  std::cin >> smallest_number;

  int largest_number{};
  std::cout << "Please provide the larrgest number: " << std::endl;
  std::cin >> largest_number;

  std::uniform_int_distribution distribution{smallest_number, largest_number};
  const int generated_random_number = distribution(random_engine);

  std::cout << "I've generated a number. Try to guess it!" << std::endl;

  int number_of_guesses = 0;
  bool number_found = false;
  int current_guess{};

  while (!number_found) {
    std::cout << "Please provide the next guess: ";
    std::cin >> current_guess;
    number_of_guesses++;

    if (current_guess == generated_random_number) {
      number_found = true;
    } else if (current_guess < generated_random_number) {
      std::cout << "Your number is too small. Try again!" << std::endl;
    } else {
      std::cout << "Your number is too big. Try again!" << std::endl;
    }
  }

  std::cout << "You've done it! You guessed the number "
            << generated_random_number << " in " << number_of_guesses
            << " guesses!" << std::endl;

  return 0;
}
