#include "builtins.hpp"
#include <iostream>

namespace sh {
namespace builtins {

void exit(std::string args) { std::exit(0); };

void echo(std::string args) { std::cout << args << std::endl; };

} // namespace builtins
} // namespace sh
