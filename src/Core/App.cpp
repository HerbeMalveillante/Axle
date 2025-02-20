#define GLFW_INCLUDE_NONE

#include "Core/App.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <iostream>

namespace Axle::Core {

unsigned int App::height = 600;
unsigned int App::width = 800;
std::string App::title = "Axle Engine";
bool App::isReady = false;
GLFWwindow *App::window = nullptr;

void App::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void App::ProcessInput() {
  if (glfwGetKey(App::window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(App::window, true);
  }
}

void App::Init(unsigned int width, unsigned int height, std::string title) {

  float vertices[] = {
      -0.5f, -0.5f, 0.0f, // bottom left
      0.5f,  -0.5f, 0.0f, // bottom right
      0.0f,  0.5f,  0.0f  // top
  };

  App::width = width;
  App::height = height;
  App::title = title;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Window creation
  App::window = glfwCreateWindow(App::width, App::height, App::title.c_str(),
                                 nullptr, nullptr);
  if (App::window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(App::window);

  // GLAD initialization
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return;
  }

  // Vertex buffer object creation
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  // Bind the buffer to the GL_ARRAY_BUFFER target
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // Copy the vertices data into the buffer's memory
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Set up the callback function for when the window is resized
  glfwSetFramebufferSizeCallback(App::window, App::framebuffer_size_callback);
}

void App::Clear(const Color clearColor) {
  glClearColor(clearColor.getRf(), clearColor.getGf(), clearColor.getBf(),
               clearColor.getAf());
  glClear(GL_COLOR_BUFFER_BIT);
}

bool App::ShouldClose() { return glfwWindowShouldClose(App::window); }

void App::SwapBuffers() { glfwSwapBuffers(App::window); }

void App::PollEvents() { glfwPollEvents(); }

void App::Exit() { glfwTerminate(); }

} // namespace Axle::Core
