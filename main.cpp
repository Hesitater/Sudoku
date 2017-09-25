#include <iostream>
#include "SudokuGenerator.h"
#include "SudokuLoader.h"
#include "SudokuSolver.h"
#include "DLXSolver.h"
#include "DLXGenerator.h"
#include "fstream"

#define sudokuRowCount 9
using namespace std;

void solvePuzzle(fstream& puzzleFile){
    //Create loader
    SudokuLoader loader = SudokuLoader();
    vector<vector<int>> sudokuSet = loader.loadFromFile(puzzleFile);

    //Solve sudokus
    vector<vector<int>> answers;
    for (unsigned int j = 0; j < sudokuSet.size(); ++j) {
        SudokuSolver solver = SudokuSolver();
        DLXNode* listHead = new DLXNode();
        vector<int> answer;
        solver.solveSudoku(listHead, sudokuSet[j], answer);
        answers.push_back(answer);
    }

/*
    //Debugging code: console output
    for (int k = 0; k < answers.size(); ++k) {
        for (int i = 0; i < answers[k].size(); ++i) {
            cout << answers[k][i] << endl;
        }
        cout << "\n" <<endl;
    }
*/

    //Save solution to file
    fstream solutionFile;
    solutionFile.open("sudoku.txt", ios::out);
    loader.writeToFile(answers, solutionFile);
    solutionFile.close();
}

void createSudoku(fstream& sudokuFile, int sudokuCount){
    //Generate sudokus
    SudokuGenerator generator = SudokuGenerator();
    vector<vector<int>> answers = generator.generateSudokus(sudokuCount);

    //Save answers to file
    SudokuLoader loader = SudokuLoader();
    loader.writeToFile(answers, sudokuFile);
}

int main(int argc, char* argv[]) {
    /* Debugging code: DLXSolver
    DLXGenerator dlxGenerator = DLXGenerator();
    DLXNode* listHead = new DLXNode();
    vector<ColumnHead*> columnHeads = dlxGenerator.createColumnHeads(listHead, 4);
    vector<vector<int>> matrix = {{0,1},{2,3},{0,1,2},{3}};
    for (int i = 0; i < matrix.size(); ++i) {
        dlxGenerator.appendLine(columnHeads, matrix[i], i);
    }

    DLXSolver solver = DLXSolver();
    vector<int> tempSolution;
    vector<vector<int>> lastSolution;
    solver.solveWithCertainAnswers(listHead, tempSolution, lastSolution, 1, 0);

    for (int j = 0; j < lastSolution.size(); ++j) {
        for (int i = 0; i < lastSolution[j].size(); ++i) {
            cout << lastSolution[j][i] << endl;
        }
    }*/

    if (strcmp(argv[1], "-s") == 0) { //Solve puzzle from file
        fstream puzzleFile;
        puzzleFile.open(argv[2], ios::in);
        solvePuzzle(puzzleFile);
        puzzleFile.close();
    } else if (strcmp(argv[1], "-c") == 0) { //Create puzzle file
        fstream sudokuFile;
        sudokuFile.open("sudoku.txt", ios::out);
        createSudoku(sudokuFile, atoi(argv[2]));
        sudokuFile.close();
    }

    return 0;
}

