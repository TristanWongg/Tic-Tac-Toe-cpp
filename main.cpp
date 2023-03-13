#include <iostream>
#include <string>

using namespace std;

void displayBoard();
void playerTurn();
void switchTurns();
bool checkWin();

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char ch = 'X';
bool draw = false;
int winner;

void displayBoard(){
    system("clear");
    
    cout << "\tTIC-TAC-TOE!\n\n";
    cout << "Player 1 - X \t Player 2 - O\n\n";

    cout << "\t|\t|\n";
    cout << "   " << board[0][0] << "    |   " << board[0][1] << "   |   " << board[0][2] << "\n";
    cout << "________|_______|________\n";
    cout << "\t|\t|\n";
    cout << "   " << board[1][0] << "    |   " << board[1][1] << "   |   " << board[1][2] << "\n";
    cout << "________|_______|________\n";
    cout << "\t|\t|\n";
    cout << "   " << board[2][0] << "    |   " << board[2][1] << "   |   " << board[2][2] << "\n";
    cout << "\t|\t|\n\n";
}

void playerTurn() {   
    int selection, row, col;
    
    if (ch == 'X') {
        cout << "Player 1 - your turn (X): ";
    } else {
        cout << "Player 2 - your turn (O): ";
    }

    while(!(cin >> selection) || selection > 9 || selection < 1){
        cout << "Invalid input, try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    switch(selection){
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: exit(0);
    }

   if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "This spot is already filled, pick another spot\n";
        playerTurn();
    } else {
        board[row][col] = ch;
        switchTurns();
    }
    displayBoard();
}


void switchTurns() {
    if (ch == 'X'){
        ch = 'O';
    } else {
        ch = 'X';
    }
}

bool checkWin() {
    //check row or column wins
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || 
            board[0][i] == board[1][i] && board[0][i] == board[2][i]
        ) {
            winner = (ch == 'X') ? 2 : 1;
            return true;
        }
    }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[2][0] == board[1][1] && board[2][0] == board[0][2]
    ) {
        winner = (ch == 'X') ? 2 : 1;
        return true;
    }

    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                return false;
            } 
        }
    }
    draw = true;
    return true;
}

int main() {
    while (!checkWin()) {
        displayBoard();
        playerTurn();
        checkWin();
    }

    string result = draw ? "DRAW!\n" : "PLAYER " + to_string(winner) + " WINS!\n";
    cout << result;
}
