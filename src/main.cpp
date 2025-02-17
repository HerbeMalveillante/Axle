#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include <iostream>

// Set up viewport
// x, y are the lower left corner of the window
// We could actually set the viewport dimensions at values smaller than
// GLFW's dimension : then all the OpenGL rendering will be displayed in a
// smaller window, and we could for example display other elements outside the
// OpenGL viewport. This could be useful when developing a GUI for a game engine
// for example.
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  // Close the window when the user presses the escape key
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main() {

  float vertices[] = {
      -0.5f, -0.5f, 0.0f, // bottom left
      0.5f,  -0.5f, 0.0f, // bottom right
      0.0f,  0.5f,  0.0f  // top
  };

  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create a window
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
  if (window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // Initialize GLAD
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // Create the vertex buffer object
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  // Bind the buffer to the GL_ARRAY_BUFFER target
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // Copy the vertices data into the buffer's memory
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Set up the callback function for when the window is resized
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Main loop
  while (!glfwWindowShouldClose(window)) {

    // Inputs
    processInput(window);

    // Rendering commands here
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Check and call events, and swap the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
