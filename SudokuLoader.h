//
// Created by Andy on 2017/9/22.
//

#pragma once

#include "math.h"
#include <fstream>
#include <vector>

using namespace std;

class SudokuLoader {
public:
    //Load all sudoku from designated file into a vector
    vector<vector<int>> loadFromFile(fstream& file);

    //Save sudokus from sudoku set to file
    void writeToFile(vector<vector<int>>& sudokuSet, fstream& file);
};


