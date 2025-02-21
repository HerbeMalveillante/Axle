#include "Utils/Filesystem.h"
#include <fstream>

namespace Axle::Utils {

std::string LoadTextFromFile(const std::string filePath) {

  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("AxleError : Could not open file: " + filePath);
  } else {
    std::string content((std::istreambuf_iterator<char>(file)),
                        (std::istreambuf_iterator<char>()));
    return content;
  }
}

} // namespace Axle::Utils
