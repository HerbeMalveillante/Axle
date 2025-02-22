#define GLFW_INCLUDE_NONE

#include "Core/App.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Axle::Core {

// Static variables definition
unsigned int App::height = 600;
unsigned int App::width = 800;
std::string App::title = "Axle Engine";
bool App::isReady = false;

unsigned int App::minWidth = GLFW_DONT_CARE;
unsigned int App::minHeight = GLFW_DONT_CARE;
unsigned int App::maxWidth = GLFW_DONT_CARE;
unsigned int App::maxHeight = GLFW_DONT_CARE;
bool App::resizable = false;

GLFWwindow *App::window = nullptr;

void App::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  App::throwErrorIfUninitialized();
  App::width = width;
  App::height = height;
  glViewport(0, 0, width, height);
}

void App::throwErrorIfUninitialized() {
  if (!App::isReady) {
    throw std::runtime_error("AxleError : App not initialized");
  }
}

void App::ProcessInput() {
  App::throwErrorIfUninitialized();
  if (glfwGetKey(App::window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(App::window, true);
  }
}

void App::Init(unsigned int width, unsigned int height, std::string title) {

  App::width = width;
  App::height = height;
  App::title = title;
  App::resizable = false;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
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

  // Set up the callback function for when the window is resized
  glfwSetFramebufferSizeCallback(App::window, App::framebuffer_size_callback);

  // Print the renderer
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
  // Print the openGL and GLSL versions
  std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
            << std::endl;

  App::isReady = true;

  // Load the default Window Icons
  std::vector<std::string> paths = {"res/icons/16.png",  "res/icons/32.png",
                                    "res/icons/64.png",  "res/icons/128.png",
                                    "res/icons/256.png", "res/icons/512.png",
                                    "res/icons/1024.png"};
  std::vector<unsigned int> sizes = {16, 32, 64, 128, 256, 512, 1024};
  App::SetWindowIcons(paths, sizes);
}

void App::Clear(const Color clearColor) {
  glClearColor(clearColor.getRf(), clearColor.getGf(), clearColor.getBf(),
               clearColor.getAf());
  glClear(GL_COLOR_BUFFER_BIT);
}

bool App::ShouldClose() {
  App::throwErrorIfUninitialized();
  return glfwWindowShouldClose(App::window);
}

void App::SwapBuffers() {
  App::throwErrorIfUninitialized();
  glfwSwapBuffers(App::window);
}

void App::PollEvents() {
  App::throwErrorIfUninitialized();
  glfwPollEvents();
}

void App::Exit() {
  App::throwErrorIfUninitialized();
  glfwTerminate();
}

void App::SetWindowResizable(bool resizable) {
  App::throwErrorIfUninitialized();
  App::resizable = resizable;
  if (resizable) {
    glfwSetWindowAttrib(App::window, GLFW_RESIZABLE, GLFW_TRUE);
  } else {
    glfwSetWindowAttrib(App::window, GLFW_RESIZABLE, GLFW_FALSE);
  }
}

void App::SetWindowMinSize(unsigned int width, unsigned int height) {
  App::throwErrorIfUninitialized();

  App::minWidth = width;
  App::minHeight = height;
  glfwSetWindowSizeLimits(App::window, App::minWidth, App::minHeight,
                          App::maxWidth, App::maxHeight);
}
void App::SetWindowMaxSize(unsigned int width, unsigned int height) {
  App::throwErrorIfUninitialized();

  App::maxWidth = width;
  App::maxHeight = height;
  glfwSetWindowSizeLimits(App::window, App::minWidth, App::minHeight,
                          App::maxWidth, App::maxHeight);
}

unsigned int App::GetWindowWidth() {
  App::throwErrorIfUninitialized();
  return App::width;
}
unsigned int App::GetWindowHeight() {
  App::throwErrorIfUninitialized();
  return App::height;
}

void App::SetWindowIcons(std::vector<std::string> paths,
                         std::vector<unsigned int> sizes) {
  App::throwErrorIfUninitialized();
  std::vector<GLFWimage> images(paths.size());
  for (size_t i = 0; i < paths.size(); i++) {
    int width, height, nrChannels;
    unsigned char *data =
        stbi_load(paths[i].c_str(), &width, &height, &nrChannels, 0);
    if (data) {
      images[i].width = width;
      images[i].height = height;
      images[i].pixels = data;
      std::cout << "Loaded icon " << paths[i] << " with size " << width << "x"
                << height << std::endl;
    } else {
      std::cerr << "Failed to load icon " << paths[i] << std::endl;
    }
  }

  // Set the window icon
  glfwSetWindowIcon(nullptr, images.size(), images.data());

  // Free the image memory
  for (auto &image : images) {
    stbi_image_free(image.pixels);
  }
}

} // namespace Axle::Core
