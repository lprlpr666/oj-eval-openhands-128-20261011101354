#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkWin(const vector<string>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

int main() {
    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }
    
    int countX = 0, countO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') countX++;
            else if (board[i][j] == 'o') countO++;
        }
    }
    
    bool xWins = checkWin(board, 'x');
    bool oWins = checkWin(board, 'o');
    
    // Validation checks
    bool isValid = true;
    
    // Both players can't win simultaneously
    if (xWins && oWins) {
        isValid = false;
    }
    
    // X goes first, so countX should be equal to countO or countO + 1
    if (countX != countO && countX != countO + 1) {
        isValid = false;
    }
    
    // If X wins, it must have one more move than O
    if (xWins && countX != countO + 1) {
        isValid = false;
    }
    
    // If O wins, counts must be equal
    if (oWins && countX != countO) {
        isValid = false;
    }
    
    // If invalid, output "invalid"
    if (!isValid) {
        cout << "invalid" << endl;
        return 0;
    }
    
    // Determine game state
    if (xWins) {
        cout << "win" << endl;
    } else if (oWins) {
        cout << "lose" << endl;
    } else {
        // Check if board is full
        bool isFull = (countX + countO == 9);
        if (isFull) {
            cout << "tie" << endl;
        } else {
            cout << "ongoing" << endl;
        }
    }
    
    return 0;
}