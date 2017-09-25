#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sudoku/SudokuGenerator.h"
#include "../Sudoku/SudokuSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(SudokuSolverTest)
	{
	public:

		TEST_METHOD(testSolveSudoku)
		{
			vector<int> puzzle = {
				7, 3, 4, 2, 9, 6, 8, 5, 1 ,
				2 ,6 ,8 ,5 ,1 ,7, 3, 9, 4,
				0, 9, 1, 8, 4, 3, 6, 2, 7,
				9, 1, 5, 7, 3, 4, 2, 8, 6,
				6, 8, 2, 1, 5, 9, 7, 4, 0,
				3, 4, 7, 6, 8, 2, 5, 1, 9,
				8, 5, 3, 4, 7, 1, 9, 6, 2,
				4, 7, 6, 9, 2, 5, 1, 3, 8,
				1, 2, 9, 3, 6, 8, 4, 7, 0 };
			vector<int> answer;
			SudokuSolver solver = SudokuSolver();
			DLXNode* listHead = new DLXNode();
			solver.solveSudoku(listHead, puzzle, answer);

			for (unsigned int i = 0; i < answer.size(); i++) {
				char* temp = (char*)malloc(sizeof(char));
				char* output = itoa(answer[i], temp, 10);
				Logger::WriteMessage(temp);
			}
		}

		TEST_METHOD(testSolveWithMultiAnswers)
		{
			vector<int> puzzle = {
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0 ,0 ,0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0 };
			vector<vector<int>> answers;
			SudokuSolver solver = SudokuSolver();
			DLXNode* listHead = new DLXNode();
			solver.solveWithMultiAnswers(listHead, puzzle, answers, 2);

			for (unsigned int i = 0; i < answers.size(); i++) {
				for (unsigned int j = 0; j < answers[i].size(); j++)
				{
					char* temp = (char*)malloc(sizeof(char));
					char* output = itoa(answers[i][j], temp, 10);
					Logger::WriteMessage(temp);
				}
			}
		}

	};

	TEST_CLASS(SudokuGeneratorTest)
	{
	public:

		TEST_METHOD(testGenerateSudokus)
		{
			SudokuGenerator generator = SudokuGenerator();
			vector<vector<int>> sudoku = generator.generateSudokus(1);

			for (unsigned int i = 0; i < sudoku.size(); i++)
			{
				for (unsigned int j = 0; j < sudoku[i].size(); j++)
				{
					char* temp = (char*)malloc(sizeof(char));
					char* output = itoa(sudoku[i][j], temp, 10);
					Logger::WriteMessage(output);
				}
			}
		}

	};
}