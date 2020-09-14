#pragma once

#include <GLFW/glfw3.h>

extern void error_callback(int, const char*);

extern void key_callback(GLFWwindow*, int, int, int, int);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

bool in(int el, int arr[]);

bool isPaused();

bool isInserting();

bool isErasing();