#pragma once
#include "command.hpp"

namespace sh {

namespace builtins {
void exit(UserCommand *args);
void echo(UserCommand *args);
void type(UserCommand *args);
void run(UserCommand *args);
void empty(UserCommand *args);
} // namespace builtins

} // namespace sh
