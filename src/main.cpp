
#include "Core/App.h"
#include "glad/glad.h"

using namespace Axle::Core;

int main() {

  App::Init(800, 600, "Axle Engine");

  // Main loop
  while (!App::ShouldClose()) {

    // Inputs
    App::processInput();

    // Rendering commands here
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    App::SwapBuffers();
    App::PollEvents();
  }

  App::Exit();
  return 0;
}
