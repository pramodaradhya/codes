#include "Player.h"
#include <bits/stdc++.h>
using namespace std;

class GameManager {
private:
  Player *obj = new Player();

public:
  void checkTurn(char board[][10], Player active, int choice) {
    int length = 6;
    bool turn = false;

    while (!turn) {
      if (board[length][choice] != 'R' && board[length][choice] != 'B') {
        board[length][choice] = active.id;
        turn = true;
      } else {
        length--;
      }
    }
  }

  void gameWinner(Player active) {
    if (active.id == 'R')
      if (active.id == 'B')
        cout << active.name << " connected 4!" << endl;
    cout << active.name << " won the game!" << endl;
  }

  int playerInput(char board[][10], Player active) {
    int choice;
    do {
      cout << active.name << "'s turn" << endl;
      cout << "Enter column number between 1 and 7: ";
      cin >> choice;
      if (choice < 1 || choice > 7) {
        cout << "Invalid column, Please enter column numnber between 1 "
                "and 7: ";
        cin >> choice;
      }
      while (board[1][choice] == 'R' || board[1][choice] == 'B') {
        cout << "Column is full, Please enter a new column number ";
        cin >> choice;
      }
    } while (choice < 1 || choice > 7);
    return choice;
  }

  void gamePlay() {
    char board[9][10];
    Player playerOne, playerTwo;
    int choice, full, again;
    bool win;

    cout << "Player One: " << endl;
    cout << "Please enter your Name: ";
    cin >> playerOne.name;
    playerOne.id = 'R';
    cout << endl;

    cout << "Player Two: " << endl;
    cout << "Please enter your Name: ";
    cin >> playerTwo.name;
    playerTwo.id = 'B';
    cout << endl;

    full = 0;
    win = false;
    obj->printBoard(board);
    do {
      choice = playerInput(board, playerOne);
      checkTurn(board, playerOne, choice);
      cout << endl;
      obj->printBoard(board);
      win = obj->winCheck(board, playerOne);
      if (win) {
        gameWinner(playerOne);
        break;
      }

      choice = playerInput(board, playerTwo);
      checkTurn(board, playerTwo, choice);
      cout << endl;
      obj->printBoard(board);
      win = obj->winCheck(board, playerTwo);
      if (win) {
        gameWinner(playerTwo);
        break;
      }
      full = obj->fullBoard(board);
      if (full == 7) {
        cout << "The board is full, GAME DRAW!" << endl;
        break;
      }
    } while (!win || full != 7);
  }
};

void line() { cout << "------------------------------------" << endl; }
void rules() {
  cout << "---------GAME RULES----------" << endl;
  cout << "- Two-player (red & blue) game.\n- Board size is  6 rows × 7 "
          "columns.\n- A player wins if he/she is able to connect 4 dots "
          "horizontally, vertically or diagonally.\n-Draw when the matrix is "
          "fully filled. "
       << endl;
}
void howtoplay() {
  cout << "---------HOW TO PLAY----------" << endl;
  cout << "- Game always starts with the player - 1 i.e. Red(R).\n- In each "
          "step, each player can choose the column number in which they want "
          "to drop the ball.\n- Rows will be filled from bottom to top in any "
          "column."
       << endl;
}

void brief() {
  line();
  cout << "WELCOME TO CONNECT 4 GAME " << endl;
  cout << endl;
  line();
  cout << endl;
  rules();
  cout << endl;
  howtoplay();
  cout << endl;
}

int main() {
  brief();
  GameManager *game = new GameManager();
  game->gamePlay();
}