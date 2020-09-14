#pragma once

#include <vector>

static const char *vertexShaderSource = "#version 330 core\n"
                                        "layout (location = 0) in vec3 aPos;\n"
                                        "void main()\n"
                                        "{\n"
                                        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                        "}\0";

static const char *fragmentShaderSourceAlive = "#version 330 core\n"
                                               "out vec4 FragColor;\n"
                                               "void main()\n"
                                               "{\n"
                                               "FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
                                               "}\0";
static const char *fragmentShaderSourceDying1 = "#version 330 core\n"
                                               "out vec4 FragColor;\n"
                                               "void main()\n"
                                               "{\n"
                                               "FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                               "}\0";
static const char *fragmentShaderSourceDying2 = "#version 330 core\n"
                                               "out vec4 FragColor;\n"
                                               "void main()\n"
                                               "{\n"
                                               "FragColor = vec4(1.0f, 0.7f, 0.0f, 1.0f);\n"
                                               "}\0";
static const char *fragmentShaderSourceDying3 = "#version 330 core\n"
                                               "out vec4 FragColor;\n"
                                               "void main()\n"
                                               "{\n"
                                               "FragColor = vec4(0.5f, 0.2f, 0.0f, 1.0f);\n"
                                               "}\0";

void initShaderProgs();

unsigned int getShaderProgAlive();

unsigned int getShaderProgDying1();

unsigned int getShaderProgDying2();

unsigned int getShaderProgDying3();

void initVAOs(int w, int h);

std::vector< std::vector<unsigned int> > * getVAOs();

void clearGraphics();