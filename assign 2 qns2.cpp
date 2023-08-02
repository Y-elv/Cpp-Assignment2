#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// Function to print the current state of the board
void print_board(vector<vector<char>> board) {
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-----------------------------" << endl;
}

// Function to check if a move is valid
bool is_valid_move(vector<vector<char>> board, int col) {
    return (board[0][col] == ' ');
}

// Function to make a move
void make_move(vector<vector<char>> &board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = player;
            break;
        }
    }
}

// Function to check if a player has won
bool check_win(vector<vector<char>> board, char player) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }
    // Check vertical
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Initialize board
    vector<vector<char>> board(ROWS, vector<char>(COLS, ' '));
    int moves = 0;
    char current_player = PLAYER1;
    bool game_over = false;

    // Game loop
    while (!game_over) {
        // Print current state of board
        print_board(board);

        // Get move from player
        int col;
        do {
            cout << "Player " << current_player << ", enter column (1-7): ";
            cin >> col;
            col--;
        } while (!is_valid_move(board, col));

        // Make move and check for win
        make_move(board, col, current_player);
        moves++;
        if (check_win(board, current_player)) {
            cout << "Congratulations, Player " << current_player << " wins!" << endl;
            game_over = true;
        } else if (moves == ROWS * COLS) {
            cout << "It's a tie!" << endl;
            game_over = true;
        }

        // Switch player
        if (current_player == PLAYER1) {
            current_player = PLAYER2;
        } else {
            current_player = PLAYER1;
        }
    }

    return 0;
}