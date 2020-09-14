cmake_minimum_required(VERSION 3.5)
project(GameOfLife)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE LEGACY)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(GoL src/main.cpp src/utils.cpp src/grid.cpp src/graphics.cpp src/glad.c)

target_include_directories(GoL PUBLIC include)
target_link_libraries(GoL ${OPENGL_gl_LIBRARY} glfw ${CMAKE_DL_LIBS})