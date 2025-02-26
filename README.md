# Axle


The goal is to create a recreation of the Raylib library, in C++.
We want to keep some of the global states, but make most of the functions object-oriented.
We will use glad and glfw to handle the window and OpenGL context.
The rest will be done by us, with the goal of having minimal dependencies.

The global variables will be created within static class members.

Raylib is a behemoth in terms of functions, and trying to replicate it from the bottom up without a clear plan would be difficult.

It might be easier to custom-implement all features I may need using learnopengl and other tutorials, in order to come up
with my own project structure, functions, etc.

## Math functions

- Matrix4 data structure
- Vector2, Vector3 data structure
- Quaternion data structure

For vectors, one possibility would be to use a base class with
an arbitrary number of components stored in an array.

## TODOS

- Add a copy constructor to the Texture class
