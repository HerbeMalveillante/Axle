#ifndef AXLE_SHADER_H
#define AXLE_SHADER_H

#include "Graphics/Texture.h"
#include <string>

namespace Axle::Graphics {

class Shader {
private:
  unsigned int id = -1;
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
  bool compiled = false;

public:
  // disable default constructor
  Shader() = delete;

  // Copy constructor
  Shader( const Shader& other );

  Shader( std::string vertexShaderSource, std::string fragmentShaderSource );
  ~Shader();

  // Copy assignment operator
  Shader& operator=( const Shader& other );

  [[nodiscard]] unsigned int getID() const { return this->id; }
  void compile();
  void use() const;
  [[nodiscard]] bool isCompiled() const { return this->compiled; }

  void setBool( const std::string& name, bool value ) const;
  void setInt( const std::string& name, int value ) const;
  void setFloat( const std::string& name, float value ) const;

  void setVec2( const std::string& name, float x, float y ) const;
  void setVec3( const std::string& name, float x, float y, float z ) const;
  void
  setVec4( const std::string& name, float x, float y, float z, float w ) const;

  void setTexture( const std::string& name, const Texture& texture ) const;
};

} // namespace Axle::Graphics

#endif // AXLE_SHADER_H
