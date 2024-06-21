#include "builtins.hpp"
#include "command.hpp"
#include "utils.hpp"

#include <iostream>
#include <unistd.h>

namespace sh {
namespace builtins {

void exit(UserCommand *input) { std::exit(parseIntOrDefault(input->args, 0)); };

void echo(UserCommand *input) { std::cout << input->args << std::endl; };

void type(UserCommand *input) {
  UserCommand *subInput = UserCommand::parseCommand(input->args);
  if (subInput->command.name.empty()) {
    delete subInput;
    return;
  }

  if (subInput->command.type == CommandType::EXTERNAL) {
    std::string fullPath = findExecutable(subInput->command.name);

    if (fullPath.empty()) {
      std::cout << subInput->command.name << ": not found" << std::endl;
      delete subInput;
      return;
    }

    std::cout << subInput->command.name << " is " << fullPath << std::endl;
    delete subInput;
    return;
  }

  std::cout << subInput->command.name << " is a shell builtin" << std::endl;
  delete subInput;
}

void run(UserCommand *input) {
  std::string fullPath = findExecutable(input->command.name);

  if (fullPath.empty()) {
    std::cout << input->command.name << ": command not found" << std::endl;
    return;
  }

  system((fullPath + " " + input->args).c_str());
  return;
}; // namespace builtins

void empty(UserCommand *input) {
  // do nothing
}

}; // namespace builtins
} // namespace sh
