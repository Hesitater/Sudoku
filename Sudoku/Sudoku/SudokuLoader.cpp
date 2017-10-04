//
// Created by Andy on 2017/9/22.
//

#include "SudokuLoader.h"
#include <sstream>
#include <stdlib.h>

#define sudokuSize 81
#define sudokuLength 9

//Load all sudoku from designated file into a vector
vector<vector<int>> SudokuLoader::loadFromFile(fstream& file){
    vector<vector<int>> sudokuSet;
    stringstream buffer;
    string content = "";
    buffer << file.rdbuf(); //Read all content from file
    content = buffer.str();

    //Erase all spaces and returns
    unsigned int i = 0;
    while(i < content.size()) {
        if (content[i] == ' ' || content[i] == '\n') {
            content.erase(i, 1);
            continue;
        }
        i++;
    }

    //Part numbers into groups
    for (unsigned int j = 0, k = 0; j < content.size(); ++j) {
        int sudokuIndex = j / sudokuSize;
        
        if (j % sudokuSize == 0) { //Come with a new sudoku
            vector<int> newSudoku;
            newSudoku.resize(sudokuSize);
            k = 0;
            sudokuSet.push_back(newSudoku);
        }

        sudokuSet[sudokuIndex][k++] = content[j] - '0';
    }

    return sudokuSet;
}

//Save sudokus from sudoku set to file
void SudokuLoader::writeToFile(vector<vector<int>>& sudokuSet, fstream& file){
	int sudokuCount = sudokuSet.size();
	//char content[sudokuCount * (19 * 9 + 2)];
    for (unsigned int i = 0; i < sudokuCount; ++i) { //Sudoku set
        char content[19 * 9 + 2];
        int contentIndex = 0;

        for (unsigned int j = 0, k = 0; j < sudokuSize; ++j, ++k) { //One sudoku
            if (k != 0){
                content[contentIndex] = ' ';
                contentIndex++;
            }
            content[contentIndex] = sudokuSet[i][j] + '0';
            contentIndex++;

            if (k == sudokuLength - 1) {
                content[contentIndex] = '\n'; //Insert return to each end of row
                contentIndex++;
                k = -1;
            }
        }
        content[contentIndex] = '\n'; //Insert one extra return to each end of sudoku
        contentIndex++;

        content[contentIndex] = '\0';
        file << content;
    }
}