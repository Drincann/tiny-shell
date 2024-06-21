#pragma once
#include <string>

enum class CommandType { BUILTIN, EXTERNAL };

class UserCommand;
class Command {
public:
  std::string name;
  CommandType type;
  void (*func)(UserCommand *);

  Command();

  // factory
  static Command *createCommand(std::string name, CommandType type,
                                void (*func)(UserCommand *));
};

class UserCommand {
public:
  Command command;
  std::string args;

  UserCommand();

  // factory
  static UserCommand *parseCommand(std::string input);
};

// declare commands map
#include <unordered_map>

extern std::unordered_map<std::string, Command *> commands;

// declare commands initializer
void initializeCommands();
