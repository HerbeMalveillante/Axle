cmake_minimum_required(VERSION 3.30)
project(Axle)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# Add external/glfw
include_directories(external/glfw/include)
add_subdirectory(external/glfw)

# Add glad
include_directories(external/glad/include)

add_executable(Axle external/glad/src/glad.c
        src/main.cpp
        src/Core/App.cpp
        src/math/Vector2.cpp
        src/math/Point2.cpp
        src/math/Size2.cpp
        src/math/Matrix4.cpp
        src/Input/Keyboard.cpp
        src/Input/Mouse.cpp
)

target_link_libraries(Axle PRIVATE glfw)
