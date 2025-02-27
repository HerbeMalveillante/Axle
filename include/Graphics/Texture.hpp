#ifndef AXLE_TEXTURE_HPP
#define AXLE_TEXTURE_HPP

#include <string>

namespace Axle::Graphics {

class Texture {
private:
  unsigned int id = 0;
  unsigned int width = 0;
  unsigned int height = 0;
  unsigned int channels = 0;

public:
  // disable default constructor
  Texture() = delete;
  // disable copy constructor
  Texture( const Texture& other ) = delete;

  // disable copy assignment operator
  Texture& operator=( const Texture& other ) = delete;

  // TODO : Add copy constructor

  Texture( const std::string& path );
  ~Texture();

  [[nodiscard]] unsigned int getID() const { return this->id; }
};

} // namespace Axle::Graphics

#endif // AXLE_TEXTURE_HPP
