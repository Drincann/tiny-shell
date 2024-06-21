#include "builtins.hpp"
#include "command.hpp"
#include <iostream>

namespace sh {
namespace builtins {

void exit(UserCommand *input) { std::exit(0); };

void echo(UserCommand *input) { std::cout << input->args << std::endl; };

void type(UserCommand *input) {
  UserCommand *subInput = UserCommand::parseCommand(input->args);
  if (subInput->command.name.empty()) {
    delete subInput;
    return;
  }

  if (subInput->command.type == CommandType::EXTERNAL) {
    std::cout << subInput->command.name << ": not found" << std::endl;
    delete subInput;
    return;
  }

  std::cout << subInput->command.name << " is a shell builtin" << std::endl;
  delete subInput;
}

void noImpl(UserCommand *input) {
  std::cout << input->command.name << ": command not found" << std::endl;
}; // namespace builtins

void empty(UserCommand *input) {
  // do nothing
}

}; // namespace builtins
} // namespace sh
