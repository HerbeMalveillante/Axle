
#include "Core/App.h"
#include "Core/Color.h"
#include "Graphics/Shader.h"
#include "Utils/Filesystem.h"
#include "glad/glad.h"
#include <iostream>

using namespace Axle::Core;
using namespace Axle::Graphics;

int main() {

  App::Init(1200, 800, "Axle Engine");

  Color backgroundColor(ColorPreset::COLOR_DARK);

  // Shader setup
  std::string vertexShaderSource = Axle::Utils::LoadTextFromFile(
      "/Users/herbemalveillante/Code/Axle/res/shaders/default.vs");
  std::string fragmentShaderSource = Axle::Utils::LoadTextFromFile(
      "/Users/herbemalveillante/Code/Axle/res/shaders/default.fs");
  Shader defaultShader(vertexShaderSource, fragmentShaderSource);
  defaultShader.compile();

  // VBO and VAO setup
  float vertices[] = {
      -0.5f, -0.5f, 0.0f, // bottom left
      0.5f,  -0.5f, 0.0f, // bottom right
      0.0f,  0.5f,  0.0f  // top
  };
  // 0. VAO and VBO creation
  unsigned int VBO;
  unsigned int VAO;
  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);
  // 1. bind Vertex Array Object
  glBindVertexArray(VAO);
  // 2. Copy our vertices array in a buffer for OpenGL to use
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // 3. then set the vertex attributes pointers
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Main loop
  while (!App::ShouldClose()) {
    // Inputs
    App::ProcessInput();

    // Rendering commands here
    App::Clear(backgroundColor);

    defaultShader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    App::SwapBuffers();
    App::PollEvents();
  }

  App::Exit();
  return 0;
}
