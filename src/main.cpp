
#include "Core/App.hpp"
#include "Core/Color.hpp"
#include "Graphics/Shader.hpp"
#include "Graphics/Texture.hpp"
#include "Math/Mat2.hpp"
#include "Utils/Filesystem.hpp"
#include "glad/glad.h"

#include <iostream>

using namespace Axle::Core;
using namespace Axle::Graphics;
using namespace Axle::Math;

void example1()
{

  App::Init();
  App::SetWindowResizable( true );

  // Try to load a texture from file
  Texture textureTest( "res/proto/proto_wall.png" );

  std::cout << "Texture loaded with ID: " << textureTest.getID() << "\n";

  Color backgroundColor( COLOR_DARK );

  // Shader setup
  std::string vertexShaderSource =
      Axle::Utils::LoadTextFromFile( "res/shaders/default.vs" );
  std::string fragmentShaderSource =
      Axle::Utils::LoadTextFromFile( "res/shaders/default.fs" );
  Shader defaultShader( vertexShaderSource, fragmentShaderSource );
  defaultShader.compile();

  // VBO, VAO and EBO setup
  std::array<float, 32> vertices = {
    1.0F / 2,  1.0F / 2,  0.0F, // top right
    1.0F,      0.0F,      0.0F, // top right color (red)
    1.0F,      1.0F,            //  top right texture coordinate
    1.0F / 2,  -1.0F / 2, 0.0F, // bottom right
    0.0F,      1.0F,      0.0F, // bottom right color (green)
    1.0F,      0.0F,            // bottom right texture coordinate
    -1.0F / 2, -1.0F / 2, 0.0F, // bottom left
    0.0F,      0.0F,      1.0F, // bottom left color (blue)
    0.0F,      0.0F,            // bottom left texture coordinate
    -1.0F / 2, 1.0F / 2,  0.0F, // top left
    1.0F,      1.0F,      0.0F, // top left color (yellow)
    0.0F,      1.0F             // top left texture coordinate
  };
  std::array<unsigned int, 6> indices = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
  };
  // 0. VAO and VBO creation
  unsigned int VBO = 0;
  unsigned int VAO = 0;
  unsigned int EBO = 0;
  glGenBuffers( 1, &VBO );
  glGenVertexArrays( 1, &VAO );
  glGenBuffers( 1, &EBO );
  // 1. bind Vertex Array Object
  glBindVertexArray( VAO );
  // 2. copy our vertices array in a vertex buffer for OpenGL to use
  glBindBuffer( GL_ARRAY_BUFFER, VBO );
  glBufferData(
      GL_ARRAY_BUFFER, sizeof( vertices ), vertices.data(), GL_STATIC_DRAW );
  // 3. copy our index array in a element buffer for OpenGL to use
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
  glBufferData( GL_ELEMENT_ARRAY_BUFFER,
                sizeof( indices ),
                indices.data(),
                GL_STATIC_DRAW );
  // 4. then set the vertex attributes pointers
  // position attribute
  glVertexAttribPointer(
      0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), nullptr );
  glEnableVertexAttribArray( 0 );
  // color attribute
  glVertexAttribPointer(
      1,
      3,
      GL_FLOAT,
      GL_FALSE,
      8 * sizeof( float ),
      reinterpret_cast<void*>( static_cast<GLintptr>( 3 * sizeof( float ) ) ) );
  glEnableVertexAttribArray( 1 );
  // texture attribute
  glVertexAttribPointer(
      2,
      2,
      GL_FLOAT,
      GL_FALSE,
      8 * sizeof( float ),
      reinterpret_cast<void*>( static_cast<GLintptr>( 6 * sizeof( float ) ) ) );
  glEnableVertexAttribArray( 2 );

  double lastTime = glfwGetTime();
  int nbFrames = 0;

  // Main loop
  while ( !App::ShouldClose() ) {

    // Measure speed
    const double currentTime = glfwGetTime();
    nbFrames++;
    if ( currentTime - lastTime >= 1.0 ) { // If last prinf() was more than 1
                                           // sec ago printf and reset timer
      std::cout << double( nbFrames ) << " FPS\n";
      nbFrames = 0;
      lastTime += 1.0;
    }

    // Inputs
    App::ProcessInput();

    // Rendering commands here
    App::Clear( backgroundColor );

    defaultShader.use();

    // Update the position
    float offsetX = (float)sin( currentTime ) / 2;
    defaultShader.setFloat( "offsetX", offsetX );

    // Update the texture
    glBindTexture( GL_TEXTURE_2D, textureTest.getID() );
    defaultShader.setInt( "ourTexture", 0 );

    // Draw the rectangle
    glBindVertexArray( VAO );
    glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
    glBindVertexArray( 0 );

    App::SwapBuffers();
    App::PollEvents();
  }

  App::Exit();
}

void example2()
{
  Mat2 mat;
  mat.at( 0, 0 ) = 1;
  mat.at( 0, 1 ) = 2;
  mat.at( 1, 0 ) = 3;
  mat.at( 1, 1 ) = 4;
  mat.invert();
  mat *= 3;
  Mat2 mat2;
  Mat2 mat3 = mat * mat2;

  Mat2 mat4 = 2 * mat;

  std::cout << mat3.toString() << "\n";
}

int main()
{
  example1();
  return 0;
};
