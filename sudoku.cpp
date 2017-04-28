

#include "sudoku.h"
using namespace std;

//EFFECTS: prints out the sudoku board
void print_board(const int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == ONE) {
                cout << "1";
            }
            else if (board[row][col] == TWO) {
                cout << "2";
            }
            else if (board[row][col] == THREE) {
                cout << "3";
            }
            else if (board[row][col] == FOUR) {
                cout << "4";
            }
            else if (board[row][col] == FIVE) {
                cout << "5";
            }
            else if (board[row][col] == SIX) {
                cout << "6";
            }
            else if (board[row][col] == SEVEN) {
                cout << "7";
            }
            else if (board[row][col] == EIGHT) {
                cout << "8";
            }
            else if (board[row][col] == NINE) {
                cout << "9";
            }
            else {
                cout << "-";
            }
        }
        cout << '\n';
    }
}

//REQUIRES: 0 <= row && row < size
//EFFECTS: Returns true iff the row does not contain any repeat numbers
bool row_has_no_repeats(const int board[SIZE][SIZE], int row) {
    assert(row >= 0 && row < SIZE);
    int row_1 = 0;
    int row_2 = 0;
    int row_3 = 0;
    int row_4 = 0;
    int row_5 = 0;
    int row_6 = 0;
    int row_7 = 0;
    int row_8 = 0;
    int row_9 = 0;
    for (int i = 0; i < SIZE; ++i) {
        switch (board[row][i]) {
            case ONE:
                ++row_1;
                break;
            case TWO:
                ++row_2;
                break;
            case THREE:
                ++row_3;
                break;
            case FOUR:
                ++row_4;
                break;
            case FIVE:
                ++row_5;
                break;
            case SIX:
                ++row_6;
                break;
            case SEVEN:
                ++row_7;
                break;
            case EIGHT:
                ++row_8;
                break;
            case NINE:
                ++row_9;
                break;
            default:
                break;
        }
        if (row_1 > 1 || row_2 > 1 || row_3 > 1 || row_4 > 1 || row_5 > 1 ||
            row_6 > 1 || row_7 > 1 || row_8 > 1 || row_9 > 1) {
            return false;
        }
    }
    return true;
}

//REQUIRES: 0 <= col && col < size
//EFFECTS: Returns true iff the column does not contain repeat numbers
bool col_has_no_repeats(const int board[SIZE][SIZE], int col) {
    assert(col >= 0 && col < SIZE);
    int col_1 = 0;
    int col_2 = 0;
    int col_3 = 0;
    int col_4 = 0;
    int col_5 = 0;
    int col_6 = 0;
    int col_7 = 0;
    int col_8 = 0;
    int col_9 = 0;
    for (int i = 0; i < SIZE; ++i) {
        switch (board[i][col]) {
            case ONE:
                ++col_1;
                break;
            case TWO:
                ++col_2;
                break;
            case THREE:
                ++col_3;
                break;
            case FOUR:
                ++col_4;
                break;
            case FIVE:
                ++col_5;
                break;
            case SIX:
                ++col_6;
                break;
            case SEVEN:
                ++col_7;
                break;
            case EIGHT:
                ++col_8;
                break;
            case NINE:
                ++col_9;
                break;
            default:
                break;
        }
        if (col_1 > 1|| col_2 > 1 || col_3 > 1 || col_4 > 1 || col_5 > 1
            || col_6 > 1 || col_7 > 1 || col_8 > 1 || col_9 > 1) {
            return false;
        }
    }
    return true;
}

//REQUIRES: 0 <= box && box < size
//EFFECTS: Returns true iff the box does not contain repeat numbers
bool box_has_no_repeats(const int board[SIZE][SIZE], int box) {
    
    return true;
}

//EFFECTS: If the board is valid, meaning it has no repeats, then
// the function returns true
bool board_has_no_repeats(const int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        if (!row_has_no_repeats(board, row)) {
            return false;
        }
    }
    for (int col = 0; col < SIZE; ++col) {
        if (!col_has_no_repeats(board, col)) {
            return false;
        }
    }
    //if box has no repeats
    return true;
}

bool find_unassigned_cell(const int board[SIZE][SIZE], int &row, int &col) {
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (board[row][col] == UNKNOWN) {
                return true;
            }
        }
    }
    return false;
}

bool used_in_row(const int board[SIZE][SIZE], int &row, int num) {
    for (int col = 0; col < SIZE; ++col) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_col(const int board[SIZE][SIZE], int &col, int num) {
    for (int row = 0; row < SIZE; ++row) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_box(const int board[SIZE][SIZE], int boxStartRow, int boxStartCol,
                 int num) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row+boxStartRow][col+boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(const int board[SIZE][SIZE], int row, int col, int num) {
    return !used_in_row(board, row, num) && !used_in_col(board, col, num) &&
    !used_in_box(board, row- row%3, col - col%3, num);
}

bool solve(const int board[SIZE][SIZE]) {
    int row, col;
    
    // make for loop
    if (!find_unassigned_cell(board, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            //board[row][col] = num;
        }
    }
    return false;
}


