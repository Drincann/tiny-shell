#include "command.hpp"

#include <string>

// implementation
Command Command::parseCommand(std::string input) {
  Command command;
  size_t spaceIndex = input.find(" ");
  if (spaceIndex == std::string::npos) {
    command.name = input;
    command.args = "";
  } else {
    command.name = input.substr(0, spaceIndex);
    command.args = input.substr(spaceIndex + 1);
  }
  return command;
}

