#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str,
                               const std::string &delimiter);

int parseIntOrDefault(const std::string &str, int def);

std::string findExecutable(const std::string &name);
