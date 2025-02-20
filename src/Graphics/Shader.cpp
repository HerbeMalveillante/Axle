
#define GLFW_INCLUDE_NONE

#include "Graphics/Shader.h"
#include "glad/glad.h"
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

ShaderProgram::ShaderProgram(const Shader vertexShader,
                             const Shader fragmentShader) {
  this->linked = false;
  this->id = glCreateProgram();
  this->fragmentShaderID = fragmentShader.getID();
  this->vertexShaderID = vertexShader.getID();
}

// TODO : Handle Errors if Shaders are not compiled
void ShaderProgram::link() {

  if (this->linked) {
    throw std::runtime_error(
        "AxleError : Shader Program already linked, cannot link again");
  }

  glAttachShader(this->id, this->vertexShaderID);
  glAttachShader(this->id, this->fragmentShaderID);
  glLinkProgram(this->id);

  int success;
  char infoLog[512];

  glGetProgramiv(this->id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(this->id, 512, nullptr, infoLog);
    throw std::runtime_error(
        std::string("AxleError : Shader Program Linking Failed\n") + infoLog);
  } else {
    this->linked = true;
  }
}

void ShaderProgram::use() {
  if (!this->linked) {
    throw std::runtime_error(
        "AxleError : Shader Program not linked, cannot use");
  } else {
    glUseProgram(this->id);
  }
}

} // namespace Axle::Graphics
