

#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include "Core/Color.h"
#include "GLFW/glfw3.h"
#include <string>

namespace Axle::Core {
class App {

private:
  static unsigned int width;
  static unsigned int height;
  static std::string title;
  static bool isReady;

  // Framebuffer size callback function
  static void framebuffer_size_callback(GLFWwindow *window, int width,
                                        int height);

public:
  static GLFWwindow *window;
  // Input processing function
  static void ProcessInput();
  static void Init(unsigned int width, unsigned int height, std::string title);
  static void Clear(Color clearColor);
  static bool ShouldClose();
  static void SwapBuffers();
  static void PollEvents();
  static void Exit();

  // We don't want the window to be instantiated
  App() = delete;
};

} // namespace Axle::Core

#endif // WINDOW_H
