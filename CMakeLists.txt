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
        src/Core/App.cpp
        src/main.cpp
)

target_link_libraries(Axle PRIVATE glfw)
