#include <iostream>

void validateCommend(std::string input);
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  std::cout << "$ ";
  
  std::string input;
  std::getline(std::cin, input);
  validateCommend(input);
}

bool isCommandNotExists(std::string input);
void validateCommend(std::string input) {
  if (isCommandNotExists(input)) {
    std::cout << input << ": command not found" << std::endl;
  }

}

bool isCommandNotExists(std::string input) {
  return true;
}
