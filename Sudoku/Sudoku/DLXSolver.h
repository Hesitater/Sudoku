//
// Created by Andy on 2017/9/22.
//

#pragma once

#include <iostream>
#include <vector>
#include "DLXNode.h"

using namespace std;

class DLXSolver {
public:
    //Get only one solution
    bool solveWithOneAnswer(DLXNode *listHead, vector<int>& solution, int depth);

    //Get all solutions
    void solveWithAllAnswers(DLXNode *listHead, vector<int>& tempSolution, vector<vector<int>>& lastSolution, int depth);

    //Get certain amount of answers
    void solveWithCertainAnswers(DLXNode *listHead, vector<int> &tempSolution, vector<vector<int>> &lastSolution,
                                 int answerCount, int depth);

    //Cover certain rows
    void cover(ColumnHead* columnHead);

    //Uncover certain rows
    void uncover(ColumnHead* columnHead);

    //Select column with minimum one's
    ColumnHead* selectColumn(DLXNode* listHead);
};