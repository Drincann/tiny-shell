#include "headers/utils.hpp"

#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>

std::vector<std::string> split(const std::string &str,
                               const std::string &delimiter) {
  std::vector<std::string> result;
  size_t start = 0;
  size_t end = 0;

  while ((end = str.find(delimiter, start)) != std::string::npos) {
    result.push_back(str.substr(start, end - start));
    start = end + delimiter.length();
  }

  result.push_back(str.substr(start));
  return result;
}

int parseIntOrDefault(const std::string &str, int def) {
  try {
    return std::stoi(str);
  } catch (std::invalid_argument &e) {
    return def;
  }
}

std::string findExecutable(const std::string &name) {
  char *path = getenv("PATH");
  std::vector<std::string> paths = split(std::string(path), ":");

  for (std::string p : paths) {
    std::string fullPath = p + "/" + name;
    if (access(fullPath.c_str(), F_OK) == 0) {
      return fullPath;
    }
  }

  return "";
}
