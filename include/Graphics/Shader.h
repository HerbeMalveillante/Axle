#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace Axle::Graphics {

class Shader {
private:
  unsigned int id;
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
  bool compiled;

public:
  Shader(std::string vertexShaderSource, std::string fragmentShaderSource);
  ~Shader();

  void compile();
  void use();
  inline bool isCompiled() { return this->compiled; }
};

} // namespace Axle::Graphics

#endif // SHADER_H
