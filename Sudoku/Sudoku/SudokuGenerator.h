//
// Created by Andy on 2017/9/22.
//

#pragma once

#include <vector>
#include "DLXGenerator.h"
#include "SudokuSolver.h"

using namespace std;

class SudokuGenerator{
public:
    vector<vector<int>> generateSudokus(int sudokuCount);
};
