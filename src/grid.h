#pragma once

#include <vector>


struct Grid {
    int w, h;
    std::vector< std::vector<int> > layout;
};

Grid * initGrid(int w, int h);

void updateGrid();

void editGrid(int i, int j, bool alive);

void printGrid();