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
  inline unsigned int getID() const { return this->id; };
};

class ShaderProgram {
private:
  unsigned int id;
  unsigned int vertexShaderID;
  unsigned int fragmentShaderID;
  bool linked;

public:
  ShaderProgram(Shader vertexShader, Shader fragmentShader);
  inline unsigned int getID() const { return this->id; };

  void link();
  void use();
};

} // namespace Axle::Graphics

#endif // SHADER_H
