
#define GLFW_INCLUDE_NONE

#include "Graphics/Shader.hpp"
#include "Core/Errors.hpp"
#include "glad/glad.h"
#include <array>

#include <string>

namespace Axle::Graphics {

// Copies the sources of the shaders, but the copy is not compiled
Shader::Shader( const Shader& other )
    : vertexShaderSource( other.vertexShaderSource ),
      fragmentShaderSource( other.fragmentShaderSource )
{
}

Shader::Shader( std::string vertexShaderSource,
                std::string fragmentShaderSource )
    : vertexShaderSource( std::move( vertexShaderSource ) ),
      fragmentShaderSource( std::move( fragmentShaderSource ) )
{
}

Shader::~Shader()
{
  if ( this->compiled ) {
    glDeleteProgram( this->id );
  }
}

// Copy assignment operator
// Copies the sources of the shaders, but the copy is not compiled
Shader& Shader::operator=( const Shader& other )
{
  if ( this == &other ) {
    return *this;
  }

  this->vertexShaderSource = other.vertexShaderSource;
  this->fragmentShaderSource = other.fragmentShaderSource;

  return *this;
}

void Shader::compile()
{

  // Register the vertex and fragment shaders
  unsigned int vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
  unsigned int fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );

  // Fetch the source code of the shaders
  const char* vertexShaderSource = this->vertexShaderSource.c_str();
  const char* fragmentShaderSource = this->fragmentShaderSource.c_str();

  // Compile the vertex shader
  glShaderSource( vertexShaderID, 1, &vertexShaderSource, nullptr );
  glCompileShader( vertexShaderID );

  // Check for compilation errors
  int success = 0;
  std::array<char, 512> infoLog = { 0 };
  glGetShaderiv( vertexShaderID, GL_COMPILE_STATUS, &success );
  if ( !(bool)success ) {
    glGetShaderInfoLog( vertexShaderID, 512, nullptr, infoLog.data() );
    // Clean up and throw an exception
    glDeleteShader( vertexShaderID );
    throw Core::ShaderCompilationError( "vertex", infoLog.data() );
    return;
  }

  // Compile the fragment shader
  glShaderSource( fragmentShaderID, 1, &fragmentShaderSource, nullptr );
  glCompileShader( fragmentShaderID );

  // Check for compilation errors
  glGetShaderiv( fragmentShaderID, GL_COMPILE_STATUS, &success );
  if ( !(bool)success ) {
    glGetShaderInfoLog( fragmentShaderID, 512, nullptr, infoLog.data() );
    // Clean up and throw an exception
    glDeleteShader( vertexShaderID );
    throw Core::ShaderCompilationError( "fragment", infoLog.data() );
    return;
  }

  // Register and link the shader program
  this->id = glCreateProgram();
  glAttachShader( this->id, vertexShaderID );
  glAttachShader( this->id, fragmentShaderID );
  glLinkProgram( this->id );

  glDeleteShader( vertexShaderID );
  glDeleteShader( fragmentShaderID );

  // Check for linking errors
  glGetProgramiv( this->id, GL_LINK_STATUS, &success );
  if ( !(bool)success ) {
    glGetProgramInfoLog( this->id, 512, nullptr, infoLog.data() );
    throw Core::ShaderLinkingError( infoLog.data() );
    return;
  }

  this->compiled = true;
}

void Shader::use() const
{
  if ( !this->compiled ) {
    throw Core::ShaderNotCompiledError();
  }

  glUseProgram( this->id );
}

void Shader::setBool( const std::string& name, bool value ) const
{
  glUniform1i( glGetUniformLocation( this->id, name.c_str() ), (int)value );
}

void Shader::setInt( const std::string& name, int value ) const
{
  glUniform1i( glGetUniformLocation( this->id, name.c_str() ), value );
}

void Shader::setFloat( const std::string& name, float value ) const
{
  glUniform1f( glGetUniformLocation( this->id, name.c_str() ), value );
}

void Shader::setVec2( const std::string& name, float x, float y ) const
{
  glUniform2f( glGetUniformLocation( this->id, name.c_str() ), x, y );
}

void Shader::setVec3( const std::string& name, float x, float y, float z ) const
{
  glUniform3f( glGetUniformLocation( this->id, name.c_str() ), x, y, z );
}

void Shader::setVec4(
    const std::string& name, float x, float y, float z, float w ) const
{
  glUniform4f( glGetUniformLocation( this->id, name.c_str() ), x, y, z, w );
}

void Shader::setTexture( const std::string& name, const Texture& texture ) const
{
  glUniform1i( glGetUniformLocation( this->id, name.c_str() ),
               (int)texture.getID() );
}

} // namespace Axle::Graphics
