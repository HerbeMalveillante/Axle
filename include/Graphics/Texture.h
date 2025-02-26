#ifndef AXLE_TEXTURE_H
#define AXLE_TEXTURE_H

#include <string>

namespace Axle::Graphics {

class Texture {
private:
  unsigned int id;
  unsigned int width;
  unsigned int height;
  unsigned int channels;

public:
  Texture(const std::string path);
  ~Texture();

  unsigned int getID() { return this->id; }
};

} // namespace Axle::Graphics

#endif // AXLE_TEXTURE_H
