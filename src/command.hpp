#include <string>

class Command {
public:
  std::string name;
  std::string args;

  // factory
  static Command parseCommand(std::string input);
};

