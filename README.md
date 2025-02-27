# Axle

Axle is a WIP 3D game engine written in C++ from scratch using OpenGL.

This project is **far** from being complete enough to be used for anything so far.

Graphical assets used in the project are from [Kenney.nl](https://kenney.nl/).

## Features

- (Almost) zero dependencies :
  - GLFW for window management and input handling
  - GLAD for OpenGL loading
  - stb_image for image loading (but I plan to replace it with my own image loader)
- Custom math library for various mathematical operations and transformations
- No need to use any other header than Axle's to use the engine
- Modern C++ practices and features
- Strict coding style and guidelines using a vast clang-tidy check set
- Blood, sweat and tears of the developer can be felt with every function call

## TODOS

- Add a copy constructor to the Texture class
- Add friend operator overloading to the Matrix and Vector classes to enable operations with the vector/matrix on the right side of the operator
