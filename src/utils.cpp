#include <iostream>
#include <GLFW/glfw3.h>

#include "utils.h"

bool paused = true;
bool insertMode = false;
bool eraseMode = false;

void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s code %d\n", description, error);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        paused = !paused;
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (!paused) {
        return;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        insertMode = true;
        eraseMode = false;
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        insertMode = false;
        eraseMode = true;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        insertMode = false;
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        eraseMode = false;
    }
}

bool in(int el, int arr[]) {
    int n = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < n; i++) {
        if (el == arr[i]) return true;
    }
    return false;
}

bool isPaused() {
    return paused;
}

bool isInserting() {
    return insertMode;
}

bool isErasing() {
    return eraseMode;
}