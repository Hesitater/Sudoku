#include <iostream>
#include "SudokuGenerator.h"
#include "SudokuLoader.h"

#define sudokuRowCount 9
#define sudokuMaximum 1000000

using namespace std;

void solvePuzzle(fstream& puzzleFile){
    //Create loader
    SudokuLoader loader = SudokuLoader();
    vector<vector<int>> sudokuSet = loader.loadFromFile(puzzleFile);
	int sudokuCount = sudokuSet.size();

    //Solve sudokus
    vector<vector<int>> answers;
	answers.resize(sudokuCount);

    for (unsigned int j = 0; j < sudokuSet.size(); ++j) {
        SudokuSolver solver = SudokuSolver();
        DLXNode* listHead = new DLXNode();
        vector<int> answer;

        if (solver.solveSudoku(listHead, sudokuSet[j], answer)) { //Answer got correctly
            answers[j] = answer;
        } else {
            cout << "No solution for sudoku No." << j + 1 << endl;
        }
    }

    //Save solution to file
    fstream solutionFile;
    solutionFile.open("sudoku.txt", ios::out);
    if (answers.size() == 0) {
        cout << "No solutions for all sudokus" << endl;
    }else {
        loader.writeToFile(answers, solutionFile);
    }
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

void reportError() {
    cout << "Program argument error" << endl;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        reportError();
        return 0;
    }

    if (strcmp(argv[1], "-s") == 0) { //Solve puzzle from file
        fstream puzzleFile;
        puzzleFile.open(argv[2], ios::in);
        solvePuzzle(puzzleFile);
        puzzleFile.close();
    } else if (strcmp(argv[1], "-c") == 0 && atoi(argv[2]) > 0 && atoi(argv[2]) <= sudokuMaximum) { //Create puzzle file
        fstream sudokuFile;
        sudokuFile.open("sudoku.txt", ios::out);
        createSudoku(sudokuFile, atoi(argv[2]));
        sudokuFile.close();
    } else {
        reportError();
    }

    return 0;
}

