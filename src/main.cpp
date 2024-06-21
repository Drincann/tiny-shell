#include <iostream>
#include <unordered_map>
#include "builtins.hpp"
#include "command.hpp"

// built-in commands container
std::unordered_map<std::string, void(*)(std::string)> commands;
void initBuiltInCommands() {
  commands["exit"] = sh::builtins::exit;
  commands["echo"] = sh::builtins::echo;
}

void eval(std::string input);
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  initBuiltInCommands();

  std::cout << "$ ";
  while (true) {
    std::string input;

    // read
    std::getline(std::cin, input);
    // eval
    eval(input);
    // print
    std::cout << "$ ";
  }
}

bool isCommandNotExists(std::string input);
void eval(std::string input) {
  // std::cout << "[DEBUG] " << input << std::endl;
  Command command = Command::parseCommand(input);
  if (isCommandNotExists(command.name)) {
    std::cout << command.name << ": command not found" << std::endl;
    return;
  }

  commands[command.name](command.args);
}

bool isCommandNotExists(std::string commandName) { 
  // check built-in commands
  if (commands.find(commandName) != commands.end()) {
    return false;
  }
  return true;
}

