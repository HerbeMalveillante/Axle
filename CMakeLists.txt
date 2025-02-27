cmake_minimum_required(VERSION 3.30)
project(Axle)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy resources to build directory
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

include_directories(include)

# Add external/glfw
include_directories(external/glfw/include)
add_subdirectory(external/glfw)

# Add glad
include_directories(external/glad/include)

# Add stb
include_directories(external/stb/include)

add_executable(Axle external/glad/src/glad.c
        src/Core/App.cpp
        src/Core/Color.cpp
        src/Core/Errors.cpp
        src/Graphics/Shader.cpp
        src/Graphics/Texture.cpp
        src/Utils/Filesystem.cpp
        src/Math/Vec2.cpp
        src/Math/Vec3.cpp
        src/Math/Vec4.cpp
        src/Math/Mat2.cpp
        src/main.cpp
)

target_link_libraries(Axle PRIVATE glfw)
