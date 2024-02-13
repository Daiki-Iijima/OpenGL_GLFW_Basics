cmake_minimum_required(VERSION 3.27)
project(opengl-glfw-basics)

set(CMAKE_CXX_STANDARD 17)

add_executable(opengl-glfw-basics main.cpp)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(opengl-glfw-basics PRIVATE opengl32 glfw)
target_link_libraries(opengl-glfw-basics PRIVATE glfw)
