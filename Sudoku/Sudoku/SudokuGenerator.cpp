//
// Created by Andy on 2017/9/20.
//

#include "SudokuGenerator.h"

#define sudokuSize 81

vector<vector<int>> SudokuGenerator:: generateSudokus(int sudokuCount) {
    vector<vector<int>> answers;

    //Create an sudoku with all zero except the first block
    vector<int> originalSudoku;
	originalSudoku.assign(sudokuSize, 0);
	originalSudoku[0] = 5; //The first one must be 5

    //Solve the zero sudoku to get sudoku outcomes
    DLXGenerator generator = DLXGenerator();
    DLXNode* listHead = new DLXNode();
    SudokuSolver solver = SudokuSolver();
    solver.solveWithMultiAnswers(listHead, originalSudoku, answers, sudokuCount);
    return answers;
}