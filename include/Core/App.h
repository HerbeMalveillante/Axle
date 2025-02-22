

#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include "Core/Color.h"
#include "GLFW/glfw3.h"
#include <string>

namespace Axle::Core {
class App {

private:
  static GLFWwindow *window;

  static unsigned int width;
  static unsigned int height;
  static std::string title;
  static bool isReady;

  static unsigned int minWidth;
  static unsigned int minHeight;
  static unsigned int maxWidth;
  static unsigned int maxHeight;
  static bool resizable;

  // Framebuffer size callback function
  static void framebuffer_size_callback(GLFWwindow *window, int width,
                                        int height);

  static void throwErrorIfUninitialized();

public:
  static void Init(unsigned int width, unsigned int height, std::string title);
  static bool ShouldClose();
  static void PollEvents();
  static void ProcessInput();
  static void Exit();

  static void Clear(Color clearColor);
  static void SwapBuffers();

  static void SetWindowResizable(bool resizable);
  static void SetWindowMinSize(unsigned int width, unsigned int height);
  static void SetWindowMaxSize(unsigned int width, unsigned int height);
  static unsigned int GetWindowWidth();
  static unsigned int GetWindowHeight();

  static bool IsReady() { return isReady; }

  // We don't want the window to be instantiated
  App() = delete;
};

} // namespace Axle::Core

#endif // WINDOW_H
