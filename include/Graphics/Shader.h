#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace Axle::Graphics {

enum class ShaderType { VERTEX_SHADER, FRAGMENT_SHADER };

class Shader {
private:
  unsigned int id;
  ShaderType type;
  std::string source;
  bool compiled;

public:
  Shader(ShaderType shaderType);

  void loadFromSource(std::string source);
};

class ShaderProgram {
private:
  unsigned int id;
  Shader vertexShader;
  Shader fragmentShader;
};

} // namespace Axle::Graphics

#endif // SHADER_H
