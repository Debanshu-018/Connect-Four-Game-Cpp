#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

char board[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "1 2 3 4 5 6 7\n";
}

bool dropPiece(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == '.') {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

bool checkWin(char player) {
    // Horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                board[i][j + 3] == player)
                return true;
        }
    }

    // Vertical
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player &&
                board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                board[i + 3][j] == player)
                return true;
        }
    }

    // Diagonal (\)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player)
                return true;
        }
    }

    // Diagonal (/)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player &&
                board[i - 3][j + 3] == player)
                return true;
        }
    }

    return false;
}

bool isBoardFull() {
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == '.')
            return false;
    }
    return true;
}

int main() {
    initializeBoard();

    char currentPlayer = 'X';
    int column;

    while (true) {
        displayBoard();

        cout << "Player " << currentPlayer
             << ", enter column (1-7): ";
        cin >> column;

        if (column < 1 || column > 7 ||
            !dropPiece(column - 1, currentPlayer)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
