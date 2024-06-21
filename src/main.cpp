#include "headers/command.hpp"

#include <iostream>

void init();
void loop();
int main() {
  init();
  loop();
}

void init() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  initBuiltins();
}

void eval(std::string input);
void loop() {
  std::cout << "$ ";
  // L(oop)
  while (true) {
    std::string input;

    // R(ead)
    std::getline(std::cin, input);
    // E(valuate)
    eval(input);
    // P(rint)
    std::cout << "$ ";
  }
}

void eval(std::string input) {
  UserCommand *command = UserCommand::parseCommand(input);
  command->command.func(command);
  delete command;
}
