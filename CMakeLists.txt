cmake_minimum_required(VERSION 3.8)
project(Sudoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SudokuGenerator.cpp DLXNode.cpp DLXSolver.cpp DLXGenerator.cpp DLXNode.h DLXGenerator.h DLXSolver.h SudokuGenerator.h SudokuLoader.cpp SudokuLoader.h SudokuSolver.cpp SudokuSolver.h DLXGeneratorTest.cpp)
add_executable(Sudoku ${SOURCE_FILES})