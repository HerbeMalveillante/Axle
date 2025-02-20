
#define GLFW_INCLUDE_NONE

#include "Graphics/Shader.h"
#include "glad/glad.h"
#include <iostream>
#include <stdexcept>

namespace Axle::Graphics {

Shader::Shader(ShaderType shaderType) {
  this->type = shaderType;
  this->compiled = false;
  switch (shaderType) {
  case ShaderType::VERTEX_SHADER:
    this->id = glCreateShader(GL_VERTEX_SHADER);
    break;
  case ShaderType::FRAGMENT_SHADER:
    this->id = glCreateShader(GL_FRAGMENT_SHADER);
    break;
  }
}

void Shader::loadFromSource(std::string source) {

  if (this->compiled) {
    throw std::runtime_error(
        "AxleError : Shader already compiled, cannot load source");
  }

  const char *src = source.c_str();
  glShaderSource(this->id, 1, &src, nullptr);
  glCompileShader(this->id);

  int success;
  char infoLog[512];
  glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);
  if (!success) {

    glGetShaderInfoLog(this->id, 512, nullptr, infoLog);
    throw std::runtime_error(
        std::string("AxleError : Shader Compilation Failed\n") + infoLog);

  } else {
    this->compiled = true;
  }
}

} // namespace Axle::Graphics
