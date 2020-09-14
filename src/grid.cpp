#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "grid.h"
#include "graphics.h"
#include "utils.h"

int aliveWith[] = {2, 3, 4, 5};
int bornWith[] = {3, 4, 5};
int lives = 10;

Grid *curGrid, *bufGrid;

// initializer for main an buffer grids
Grid * initGrid(int w, int h) {
    curGrid = new Grid();
    std::cout << curGrid << std::endl;
    curGrid->w = w;
    curGrid->h = h;
    curGrid->layout.resize(w);
    for (size_t i = 0; i < w; i++) {
        curGrid->layout[i].resize(h, 0);
    };
    bufGrid = new Grid();
    bufGrid->w = w;
    bufGrid->h = h;
    bufGrid->layout.resize(w);
    for (size_t i = 0; i < w; i++) {
        bufGrid->layout[i].resize(h, 0);
    };
    return curGrid;
}

// call only after initGrid
void updateGrid() {
    int w = curGrid->w, h = curGrid->h;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            int count = 0;
            for (int ni = -1; ni < 2; ni++) {
                for (int nj = -1; nj < 2; nj++) {
                    int shiftedW = (i + ni + w) % w, shiftedH = (j + nj + h) % h;
                    // count alive neighbours
                    count += ((ni || nj) && (curGrid->layout[shiftedW][shiftedH] == lives));
                }
            }
            // cellular automata rules
            if ((curGrid->layout[i][j] == lives) && (in(count, aliveWith))) {
                bufGrid->layout[i][j] = curGrid->layout[i][j]; // if has enough neighbours - stay alive
            } else if (curGrid->layout[i][j] == 0) {
                if (in(count, bornWith)) {
                    bufGrid->layout[i][j] = lives; // if even more neighbours - give birth
                } else {
                    bufGrid->layout[i][j] = 0; // else - stay dead
                }
            } else if (curGrid->layout[i][j] > 0) {
                bufGrid->layout[i][j] = curGrid->layout[i][j] - 1; // slowly fade away
            }
        }
    }
    Grid* temp = curGrid;
    curGrid = bufGrid;
    bufGrid = temp;
}

void editGrid(int i, int j, bool alive) {
    curGrid->layout[i][j] = alive * lives;
}

void printGrid() {
    int w = curGrid->w, h = curGrid->h;
    unsigned int shaderProgAlive = getShaderProgAlive(),
                shaderProgDying1 = getShaderProgDying1(),
                shaderProgDying2 = getShaderProgDying2(),
                shaderProgDying3 = getShaderProgDying3();

    std::vector< std::vector<unsigned int> > *vaos = getVAOs();

    glClear( GL_COLOR_BUFFER_BIT); // clear screen every frame
    glLoadIdentity();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            int n = curGrid->layout[i][j];
            if (n == 0) continue;

            // figure out what shader to user based remaining health
            if (n == lives) glUseProgram(shaderProgAlive);
            else if (n > 2 * (lives - 1) / 3) glUseProgram(shaderProgDying1);
            else if (n > (lives - 1) / 3) glUseProgram(shaderProgDying2);
            else glUseProgram(shaderProgDying3);

            glBindVertexArray((*vaos)[i][j]);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }
    }
}