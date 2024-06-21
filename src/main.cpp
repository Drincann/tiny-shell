#include "headers/command.hpp"

#include <iostream>

// built-in commands container

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

  initializeCommands();
}

void eval(std::string input);
void loop() {
  std::cout << "$ ";
  while (true) {
    std::string input;

    // REP
    std::getline(std::cin, input);
    eval(input);
    std::cout << "$ ";
  }
}

void eval(std::string input) {
  // std::cout << "[DEBUG] " << input << std::endl;
  UserCommand *command = UserCommand::parseCommand(input);
  command->command.func(command);
  delete command;
}
