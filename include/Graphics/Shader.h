#ifndef SHADER_H
#define SHADER_H

#include "Graphics/Texture.h"
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

  unsigned int getID() { return this->id; }
  void compile();
  void use();
  inline bool isCompiled() { return this->compiled; }

  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;

  void setVec2(const std::string &name, float x, float y) const;
  void setVec3(const std::string &name, float x, float y, float z) const;
  void setVec4(const std::string &name, float x, float y, float z,
               float w) const;

  void setTexture(const std::string &name, Texture texture) const;
};

} // namespace Axle::Graphics

#endif // SHADER_H
