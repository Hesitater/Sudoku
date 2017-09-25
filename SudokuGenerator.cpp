//
// Created by Andy on 2017/9/20.
//

#include "SudokuGenerator.h"

#define sudokuSize 81

vector<vector<int>> SudokuGenerator:: generateSudokus(int sudokuCount) {
    vector<vector<int>> answers;

    //Create an sudoku with all zero
    vector<int> originalSudoku;
    for (int j = 0; j < sudokuSize; ++j) {
        if (j == 0) { //The first one must be 5
            originalSudoku.push_back(5);
        }else {
            originalSudoku.push_back(0);
        }
    }

    //Solve the zero sudoku to get sudoku outcomes
    DLXGenerator generator = DLXGenerator();
    DLXNode* listHead = new DLXNode();
    SudokuSolver solver = SudokuSolver();
    solver.solveWithMultiAnswers(listHead, originalSudoku, answers, sudokuCount);
    return answers;
}