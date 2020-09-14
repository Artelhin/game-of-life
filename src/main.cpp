#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#include "graphics.h"
#include "grid.h"
#include "utils.h"

const size_t window_h = 800;
const size_t window_w = 800;
const int grid_h = 200;
const int grid_w = 200;
const int maxTPS = 30;
const int spawnRate = 40;

int main() {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) return -1;

    // create window
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(window_w, window_h,
                                          "Game of Life", NULL, NULL);
    if(!window) {
        std::cout << "Window not created" << std::endl;
        glfwTerminate();
        return -1;
    }

    // set glfw callbacks for handling editing input
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    int glVersion[2] = {-1, 1};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

    std::printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);
    std::printf("Renderer used: %s\n", glGetString(GL_RENDERER));
    std::printf("Shading Language: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    glDisable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);

    // initializing game itself
    std::cout << "Initializing grid..." << std::endl;
    Grid* curGrid = initGrid(grid_w, grid_h);

    // compile all the necessary shaders an build vaos
    std::cout << "Compiling shaders..." << std::endl;
    initShaderProgs();
    std::cout << "Constructing VAOs..." << std::endl;
    initVAOs(grid_w, grid_h);

    // set random initial state
    std::cout << "Setting random grid scene.." << std::endl;
    std::srand(time(nullptr));
    for (int i = 0; i < grid_w; i++) {
        for (int j = 0; j < grid_h; j++)
            if (std::rand() % 100 >= 100 - spawnRate) {
                editGrid(i, j, true);
            }
    }
    std::cout << "Done and ready to go!" << std::endl;

    // TPS regulations
    long long int iters = 0;
    double last = glfwGetTime(), now, delta;
    double span = 1.0 / maxTPS;

    // main cycle
    while (!glfwWindowShouldClose(window)) {
        now = glfwGetTime();
        if (!isPaused()) {
            delta += ((now - last) / span);
        }
        last = now;

        // do not update grid too fast, but render and read keys+mouse buttons as often as possible
        while (delta >= 1.0 && !isPaused()) {
            updateGrid();
            delta--;
        }

        // handling editing while paused
        if (isPaused()) {
            double x, y;
            glfwGetCursorPos(window, &x, &y);
            if (x >= 0 && x < window_w && y>=0 && y < window_h) {
                x = int(x) / (window_w / grid_w);
                y = int(y) / (window_h / grid_h);
                if (isInserting()) {
                    editGrid(x, y, true);
                }
                if (isErasing()) {
                    editGrid(x, y, false);
                }
            }
        }

        // render function
        printGrid();

        glfwSwapBuffers(window);
        glfwPollEvents();
        iters++;
    }
    std::cout << "Done " << iters << " iterations" << std::endl;
    std::cout << "Exiting..." << std::endl;

    std::cout << "Clearing graphic memory..." << std::endl;
    clearGraphics();
    glfwDestroyWindow(window);
    std::cout << "Done" << std::endl;
    glfwTerminate();

    return 0;
}