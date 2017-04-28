
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cassert>
#include <stdio.h>

const int SIZE = 9;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int NINE = 9;
const int UNKNOWN = 0;


//EFFECTS: prints a visual representation of the game board to
// standard output. Numbers are printed if specified, else a '-' appears.
void print_board(const int board[SIZE][SIZE]);

//REQUIRES: 0 <= row && row < size
//EFFECTS: Returns true iff the row does not contain any repeat numbers
bool row_has_no_repeats(const int board[SIZE][SIZE], int row);

//REQUIRES: size < MAX_SIZE and size is a positive integer
//          0 <= col && col < size
//EFFECTS: Returns true iff the column does not contain repeat numbers
bool col_has_no_repeats(const int board[SIZE][SIZE], int col);

//REQUIRES: size < MAX_SIZE and size is a positive integer
//          0 <= box && row < size
//EFFECTS: Returns true iff the box does not contain repeat numbers
bool box_has_no_repeats(const int board[SIZE][SIZE], int box);


bool board_has_no_repeats(const int board[SIZE][SIZE]);

bool find_unassigned_cell(const int board[SIZE][SIZE], int &row, int &col);

bool used_in_row(const int board[SIZE][SIZE], int &row, int num);

bool used_in_col(const int board[SIZE][SIZE], int &col, int num);

bool used_in_box(const int board[SIZE][SIZE], int boxStartRow, int boxStartCol,
                 int num);
bool isSafe(const int board[SIZE][SIZE], int row, int col, int num);

bool solve(const int board[SIZE][SIZE]);
#endif
