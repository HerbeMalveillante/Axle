#include "Graphics/Texture.h"
#include "glad/glad.h"
#include "stb_image.h"
#include <iostream>
#include <string>

namespace Axle::Graphics {

Texture::Texture(const std::string path) {
  stbi_set_flip_vertically_on_load(true);

  glGenTextures(1, &this->id);
  glBindTexture(GL_TEXTURE_2D, this->id);

  // set the texture wrapping/filtering options (on the currently bound texture
  // object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  const char *cPath = path.c_str();

  // Load the image from file
  unsigned char *data =
      stbi_load(cPath, (int *)&this->width, (int *)&this->height,
                (int *)&this->channels, 0);
  if (data) {
    GLenum format;
    if (this->channels == 1) {
      format = GL_RED;
    } else if (this->channels == 3) {
      format = GL_RGB;
    } else if (this->channels == 4) {
      format = GL_RGBA;
    } else {
      format = GL_RGB;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);
}

Texture::~Texture() { glDeleteTextures(1, &this->id); }

} // namespace Axle::Graphics
