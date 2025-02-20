
#include "Core/App.h"
#include "Core/Color.h"
#include "Graphics/Shader.h"
#include <iostream>

using namespace Axle::Core;
using namespace Axle::Graphics;

int main() {

  VertexShader vs = VertexShader();
  vs.loadFromSource("");

  Color backgroundColor(ColorPreset::COLOR_DARK);
  std::cout << std::string(backgroundColor) << std::endl;

  App::Init(1200, 800, "Axle Engine");

  // Main loop
  while (!App::ShouldClose()) {

    // Inputs
    App::ProcessInput();

    // Rendering commands here
    App::Clear(backgroundColor);

    App::SwapBuffers();
    App::PollEvents();
  }

  App::Exit();
  return 0;
}
