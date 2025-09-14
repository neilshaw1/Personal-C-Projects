#include "Board.h"
#include "Computer.h"
#include <iostream>
using namespace std;
Board::Board() { // The constuctor for Board can be empty since we don't need to
                 // pass anything into it
}
vector<vector<char>>
Board::getVector() { // This just returns the board 2D vector
  return board;
}

void Board::updateBoard(
    vector<vector<char>>
        updatedBoard) { // This takes the updated board as a parameter and sets
                        // the board used in this class to the updated version
  board = updatedBoard;
}

void Board::displayBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3;
         j++) { // This just prints each value of the board 2D vector and adds
                // lines and plus symbols to make it look better
      cout << board[i][j];
      if (j < 2)
        cout << "|";
    }
    cout << endl;
    if (i < 2)
      cout << "-+-+-" << endl;
  }
}
