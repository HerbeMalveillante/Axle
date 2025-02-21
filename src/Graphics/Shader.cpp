
#define GLFW_INCLUDE_NONE

#include "Graphics/Shader.h"
#include "glad/glad.h"
#include <stdexcept>

namespace Axle::Graphics {

Shader::Shader(std::string vertexShaderSource,
               std::string fragmentShaderSource) {
  this->vertexShaderSource = vertexShaderSource;
  this->fragmentShaderSource = fragmentShaderSource;
  this->compiled = false;
}

Shader::~Shader() {
  if (this->compiled) {
    glDeleteProgram(this->id);
  }
}

void Shader::compile() {

  // Register the vertex and fragment shaders
  unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

  // Fetch the source code of the shaders
  const char *vertexShaderSource = this->vertexShaderSource.c_str();
  const char *fragmentShaderSource = this->fragmentShaderSource.c_str();

  // Compile the vertex shader
  glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShaderID);

  // Check for compilation errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
    // Clean up and throw an exception
    glDeleteShader(vertexShaderID);
    throw std::runtime_error("AxleError : Vertex shader compilation failed: " +
                             std::string(infoLog));
    return;
  }

  // Compile the fragment shader
  glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShaderID);

  // Check for compilation errors
  glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
    // Clean up and throw an exception
    glDeleteShader(vertexShaderID);
    throw std::runtime_error(
        "AxleError : Fragment shader compilation failed: " +
        std::string(infoLog));
    return;
  }

  // Register and link the shader program
  this->id = glCreateProgram();
  glAttachShader(this->id, vertexShaderID);
  glAttachShader(this->id, fragmentShaderID);
  glLinkProgram(this->id);

  glDeleteShader(vertexShaderID);
  glDeleteShader(fragmentShaderID);

  // Check for linking errors
  glGetProgramiv(this->id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(this->id, 512, NULL, infoLog);
    throw std::runtime_error("AxleError : Shader program linking failed: " +
                             std::string(infoLog));
    return;
  }

  this->compiled = true;
}

void Shader::use() {
  if (!this->compiled) {
    throw std::runtime_error("AxleError : Shader program not compiled");
  } else {
    glUseProgram(this->id);
  }
}

} // namespace Axle::Graphics
