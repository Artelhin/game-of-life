#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "graphics.h"

unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
};

unsigned int shaderProgramAlive,
        shaderProgramDying1,
        shaderProgramDying2,
        shaderProgramDying3;

std::vector< std::vector<unsigned int> > vaos;
std::vector< std::vector<unsigned int> > vbos;
std::vector< std::vector<unsigned int> > ebos;

void initShaderProgs() {
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceAlive, NULL);
    glCompileShader(fragmentShader);

    shaderProgramAlive = glCreateProgram();
    glAttachShader(shaderProgramAlive, vertexShader);
    glAttachShader(shaderProgramAlive, fragmentShader);
    glLinkProgram(shaderProgramAlive);

    glDeleteShader(fragmentShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceDying1, NULL);
    glCompileShader(fragmentShader);

    shaderProgramDying1 = glCreateProgram();
    glAttachShader(shaderProgramDying1, vertexShader);
    glAttachShader(shaderProgramDying1, fragmentShader);
    glLinkProgram(shaderProgramDying1);

    glDeleteShader(fragmentShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceDying2, NULL);
    glCompileShader(fragmentShader);

    shaderProgramDying2 = glCreateProgram();
    glAttachShader(shaderProgramDying2, vertexShader);
    glAttachShader(shaderProgramDying2, fragmentShader);
    glLinkProgram(shaderProgramDying2);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceDying3, NULL);
    glCompileShader(fragmentShader);

    shaderProgramDying3 = glCreateProgram();
    glAttachShader(shaderProgramDying3, vertexShader);
    glAttachShader(shaderProgramDying3, fragmentShader);
    glLinkProgram(shaderProgramDying3);

    glDeleteShader(fragmentShader);
}

// call after initializing grids
void initVAOs(int w, int h) {
    vaos.resize(w);
    for (int i = 0; i < w; i++) {
        vaos[i].resize(h);
    }
    vbos.resize(w);
    for (int i = 0; i < w; i++) {
        vbos[i].resize(h);
    }
    ebos.resize(w);
    for (int i = 0; i < w; i++) {
        ebos[i].resize(h);
    }

    float scaleW = float(w) / 2, scaleH = float(h) / 2;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            // coords of every square of the grid
            float verts[] = {
                    -1 + float(i) / scaleW, 1 - float(j) / scaleH, 0.0f,
                    -1 + (float(i) + 1) / scaleW, 1 - float(j) / scaleH, 0.0f,
                    -1 + (float(i) + 1) / scaleW, 1 - (float(j) - 1) / scaleH, 0.0f,
                    -1 + float(i) / scaleW, 1 - (float(j) - 1) / scaleH, 0.0f
            };

            unsigned int vao, vbo, ebo;
            glGenVertexArrays(1, &vao);
            glGenBuffers(1, &vbo);
            glGenBuffers(1, &ebo);

            glBindVertexArray(vao);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // store every object for clearing memory in the end
            vaos[i][j] = vao;
            vbos[i][j] = vbo;
            ebos[i][j] = ebo;
        }
    }
}

unsigned int getShaderProgAlive() {
    return shaderProgramAlive;
}

unsigned int getShaderProgDying1() {
    return shaderProgramDying1;
}

unsigned int getShaderProgDying2() {
    return shaderProgramDying2;
}

unsigned int getShaderProgDying3() {
    return shaderProgramDying3;
}

std::vector< std::vector<unsigned int> > * getVAOs() {
    return &vaos;
}

// cleanup function
void clearGraphics() {
    for (size_t i = 0; i < vaos.size(); i++) {
        for (size_t j = 0; j < vaos[0].size(); j++) {
            glDeleteVertexArrays(1, &vaos[i][j]);
        }
    }
    for (size_t i = 0; i < vbos.size(); i++) {
        for (size_t j = 0; j < vbos[0].size(); j++) {
            glDeleteBuffers(1, &vbos[i][j]);
        }
    }
    for (size_t i = 0; i < ebos.size(); i++) {
        for (size_t j = 0; j < ebos[0].size(); j++) {
            glDeleteBuffers(1, &ebos[i][j]);
        }
    }
    glDeleteProgram(shaderProgramAlive);
    glDeleteProgram(shaderProgramDying1);
    glDeleteProgram(shaderProgramDying2);
    glDeleteProgram(shaderProgramDying3);

}