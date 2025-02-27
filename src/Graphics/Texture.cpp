#include "Graphics/Texture.hpp"
#include "glad/glad.h"
#include "stb_image.h"
#include <iostream>
#include <string>

namespace Axle::Graphics {

Texture::Texture( const std::string& path )
{
  stbi_set_flip_vertically_on_load( 1 );

  glGenTextures( 1, &this->id );
  glBindTexture( GL_TEXTURE_2D, this->id );

  // set the texture wrapping/filtering options (on the currently bound texture
  // object)
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glTexParameteri(
      GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

  const char* cPath = path.c_str();

  // Load the image from file
  int width = (int)this->width;
  int height = (int)this->height;
  int channels = (int)this->channels;
  unsigned char* data = stbi_load( cPath, &width, &height, &channels, 0 );
  if ( (bool)data ) {
    GLenum format = 0;
    switch ( channels ) {
      case 1:
        format = GL_RED;
        break;
      case 3:
        format = GL_RGB;
        break;
      case 4:
        format = GL_RGBA;
        break;
      default:
        format = GL_RGB;
        break;
    }

    glTexImage2D( GL_TEXTURE_2D,
                  0,
                  (int)format,
                  width,
                  height,
                  0,
                  format,
                  GL_UNSIGNED_BYTE,
                  data );
    glGenerateMipmap( GL_TEXTURE_2D );
  }
  else {
    std::cout << "Failed to load texture\n";
  }
  stbi_image_free( data );
}

Texture::~Texture() { glDeleteTextures( 1, &this->id ); }

} // namespace Axle::Graphics
