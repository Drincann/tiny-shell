#include "command.hpp"
#include "builtins.hpp"

#include <cstdlib>
#include <string>

// impl commands container
std::unordered_map<std::string, Command *> commands;

void initializeCommands() {
  commands["echo"] =
      Command::createCommand("echo", CommandType::BUILTIN, sh::builtins::echo);
  commands["exit"] =
      Command::createCommand("exit", CommandType::BUILTIN, sh::builtins::exit);
  commands["type"] =
      Command::createCommand("type", CommandType::BUILTIN, sh::builtins::type);
  commands["pwd"] =
      Command::createCommand("pwd", CommandType::BUILTIN, sh::builtins::pwd);
}

// impl Command
UserCommand *UserCommand::parseCommand(std::string input) {
  UserCommand *userCommand = new UserCommand();

  if (input.empty()) {
    userCommand->command.name = "";
    userCommand->command.type = CommandType::BUILTIN;
    userCommand->command.func = sh::builtins::empty;
    return userCommand;
  }

  size_t spaceIndex = input.find(" ");
  std::string name, args;
  if (spaceIndex == std::string::npos) {
    name = input;
    args = "";
  } else {
    name = input.substr(0, spaceIndex);
    args = input.substr(spaceIndex + 1);
  }

  // check built-in commands
  userCommand->args = args;
  if (commands[name] == nullptr) {
    userCommand->command.name = name;
    userCommand->command.type = CommandType::EXTERNAL;
    userCommand->command.func = sh::builtins::run;
  } else {
    userCommand->command = *commands[name];
  }

  return userCommand;
}

// impl UserCommand
UserCommand::UserCommand() {}

// impl Command
Command::Command() {}

Command *Command::createCommand(std::string name, CommandType type,
                                void (*func)(UserCommand *)) {
  Command *command = new Command();
  command->name = name;
  command->type = type;
  command->func = func;

  return command;
}
