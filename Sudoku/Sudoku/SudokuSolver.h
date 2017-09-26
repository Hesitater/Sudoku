//
// Created by Andy on 2017/9/23.
//

#include "DLXGenerator.h"
#include "DLXSolver.h"
#include <vector>

#pragma once

using namespace std;

class SudokuSolver {
public:
    vector<vector<int>> elementSubscriptss; //One set of element stands for one number's info

    //Transform sudoku into orthogonal list
    void transformToList(vector<int>& sudokuArray, DLXNode *listHead);

    //Invoke DLXSolver's solve() to solve one sudoku, transform solution into array
    bool solveSudoku(DLXNode *listHead, vector<int>& sudoku, vector<int> &answer);

    //Solve one sudoku with different answers
    void solveWithMultiAnswers(DLXNode* listHead, vector<int>& sudoku, vector<vector<int>>& answers, int answerCount);

    //Transform dlx solution into sudoku answer
    void solutionToAnswer(vector<int>& solution, vector<int>& answer);

    int indexToRow(int index, int rowLength);

    int indexToColumn(int index, int columnLenghth);

    void appendOneSubscript(vector<vector<int>>& subscriptss, int index, int value);

    int getValue(int index);
};



