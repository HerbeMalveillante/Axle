
#include "Core/App.h"
#include "Core/Color.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Utils/Filesystem.h"
#include "glad/glad.h"
#include <iostream>

using namespace Axle::Core;
using namespace Axle::Graphics;

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
  float vertices[] = {
    0.5f,  0.5f,  0.0f, // top right
    1.0f,  0.0f,  0.0f, // top right color (red)
    1.0f,  1.0f,        //  top right texture coordinate
    0.5f,  -0.5f, 0.0f, // bottom right
    0.0f,  1.0f,  0.0f, // bottom right color (green)
    1.0f,  0.0f,        // bottom right texture coordinate
    -0.5f, -0.5f, 0.0f, // bottom left
    0.0f,  0.0f,  1.0f, // bottom left color (blue)
    0.0f,  0.0f,        // bottom left texture coordinate
    -0.5f, 0.5f,  0.0f, // top left
    1.0f,  1.0f,  0.0f, // top left color (yellow)
    0.0f,  1.0f         // top left texture coordinate
  };
  unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
  };
  // 0. VAO and VBO creation
  unsigned int VBO;
  unsigned int VAO;
  unsigned int EBO;
  glGenBuffers( 1, &VBO );
  glGenVertexArrays( 1, &VAO );
  glGenBuffers( 1, &EBO );
  // 1. bind Vertex Array Object
  glBindVertexArray( VAO );
  // 2. copy our vertices array in a vertex buffer for OpenGL to use
  glBindBuffer( GL_ARRAY_BUFFER, VBO );
  glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );
  // 3. copy our index array in a element buffer for OpenGL to use
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
  glBufferData(
      GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );
  // 4. then set the vertex attributes pointers
  // position attribute
  glVertexAttribPointer(
      0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( float ), (void*)0 );
  glEnableVertexAttribArray( 0 );
  // color attribute
  glVertexAttribPointer( 1,
                         3,
                         GL_FLOAT,
                         GL_FALSE,
                         8 * sizeof( float ),
                         (void*)( 3 * sizeof( float ) ) );
  glEnableVertexAttribArray( 1 );
  // texture attribute
  glVertexAttribPointer( 2,
                         2,
                         GL_FLOAT,
                         GL_FALSE,
                         8 * sizeof( float ),
                         (void*)( 6 * sizeof( float ) ) );
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
      std::cout << double( nbFrames ) << " FPS" << std::endl;
      nbFrames = 0;
      lastTime += 1.0;
    }

    // Inputs
    App::ProcessInput();

    // Rendering commands here
    App::Clear( backgroundColor );

    defaultShader.use();

    // Update the position
    float offsetX = sin( currentTime ) / 2.0f;
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

void example2() { App::Init( 800, 800, "test" ); }

int main()
{
  example1();
  return 0;
};
