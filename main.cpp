

#include <iostream>
#include "sudoku.h"

using namespace std;

static void make_board(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cin >> board[row][col];
        }
        cout << '\n';
    }
    if (solve(board)) {
        cout << board << '\n';
        cout << "This sudoku board has been solved!\n";
        cout << "Do you want to solve another board? (Yes/No)?\n";
        string s;
        cin >> s;
        if (s == "Yes" || s == "yes") {
            make_board(board);
        }
        else {
            cout << "Ending sudoku solver program\n";
            exit(1);
        }
    }
    else {
        cout << "Board cannot be solved\n";
        cout << "Input a new board (Yes/No)?\n";
        string value;
        cin >> value;
        if (value == "Yes" || value == "yes") {
            make_board(board);
        }
        else if (value == "No" || value == "no") {
            cout << "Ending sudoku solver program\n";
            exit(1);
        }
    }
}

int main() {
    int board[SIZE][SIZE];
    cout << "Make your own sudoku board! Make sure the board is 9x9:\n";
    make_board(board);
}
