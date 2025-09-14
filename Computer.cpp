#include "Computer.h"
#include "Board.h"
#include <iostream>
using namespace std;

// Constructor for Computer class
Computer::Computer(int *m) {
  strat = 0; // Initialize strategy to 0
  moves = m; // Initialize moves pointer
}

// Method to determine win, lose, or draw situation
bool Computer::winLoseOrDraw(Board &b) {
  // Check if X has won
  if (checkWin('X', b)) {
    cout << "=======================================" << endl;
    cout << "Congratulations! You win!" << endl;
    return true;
  }
  // Check if O has won
  else if (checkWin('O', b)) {
    cout << "=======================================" << endl;
    cout << "Computer wins! You lose." << endl;
    return true;
  }
  // Check if it's a draw
  else if (getMoves() == 9) {
    cout << "=======================================" << endl;
    cout << "It's a draw!" << endl;
    return true;
  }
  return false;
}

void Computer::nextOpenSpot(Board &b) {
  vector<vector<char>> board = b.getVector();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) { // Cycles through all the spaces in the board
      if (board[i][j] == ' ') {
        board[i][j] = 'O'; // Detects the next open spots, and places an O there
        b.updateBoard(board);
        return;
      }
    }
  }
}

bool Computer::XCanWin(Board &b) {
  vector<vector<char>> board = b.getVector();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) { // Cycles through all the spaces in the board
      if (board[i][j] == ' ') {
        board[i][j] = 'X'; // If there is an open space, an X is placed there
        b.updateBoard(board);
        if (checkWin('X', b)) { // With the newly added X, if X wins, then the
                                // computer places an O there to block X's win
          board[i][j] = 'O';
          b.updateBoard(board);
          return true;
        }
        board[i][j] = ' '; // Resets the move
        b.updateBoard(board);
      }
    }
  }
  return false;
}

bool Computer::OCanWin(Board &b) {
  vector<vector<char>> board = b.getVector();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') { // Checks if the space is open
        board[i][j] = 'O';      // Places an O in the open space
        b.updateBoard(board);
        if (checkWin('O', b)) { // With the newly added O, if O wins, then the
                                // computer continues with that move
          return true;
        }
        board[i][j] = ' '; // Resets the move if O wouldn't win on that space
        b.updateBoard(board);
      }
    }
  }
  return false;
}

void Computer::move(Board &b) {
  vector<vector<char>> board = b.getVector();
  // Force a draw when opponent starts in the corner
  if (((*moves == 1) && (board[0][0] == 'X' || board[0][2] == 'X' ||
                         board[2][0] == 'X' || board[2][2] == 'X')) ||
      (strat == 1)) {  // If it is the first move and the player plays in the
                       // corner, then this runs
    if (*moves == 1) { // When moves equals 1, then computer plays in the corner
      board[1][1] = 'O';
      b.updateBoard(board);
      strat = 1;
    } else if (OCanWin(
                   b)) { // If O can win, then the code should continue (as the
                         // board is already updated in the OCanWin function)
    } else {
      if (XCanWin(b)) { // If X can win, then the code should continue (as the
                        // board is already updated in the XCanWin function)
      } else { // If the computer doesn't need to block or win, it should play
               // in the next available edge
        if (board[0][1] == ' ') {
          board[0][1] = 'O';
          b.updateBoard(board);
        } else if (board[1][0] == ' ') {
          board[1][0] = 'O';
          b.updateBoard(board);
        } else if (board[1][2] == ' ') {
          board[1][2] = 'O';
          b.updateBoard(board);
        } else if (board[2][1] == ' ') {
          board[2][1] = 'O';
          b.updateBoard(board);
        } else { // If no edge is open, then the computer should play in the
                 // next open spot in order to force a draw
          nextOpenSpot(b);
        }
      }
    }
  }

  // Force a draw when opponent starts in the center
  else if (((*moves == 1) && (board[1][1] == 'X')) || (strat == 2)) {
    if (*moves == 1) { // If it is the first move, and opponent starts in the
                       // center, the computer should play in a corner. We know
                       // board[0][0] will be open because the player has played
                       // in the center as their first move.
      board[0][0] = 'O';
      b.updateBoard(board);
      strat = 2;
    } else if (OCanWin(
                   b)) { // If O can win, then the code should continue (as the
                         // board is already updated in the OCanWin function)
    } else {
      if (XCanWin(b)) { // If X can win, then the code should continue (as the
                        // board is already updated in the XCanWin function)
      } else {
        nextOpenSpot(b); // If the computer does not need to block or win, then
                         // it should play in the next open spot
      }
    }
  }
  // Try to win if opponent starts at the edge
  else if (((*moves == 1) && (board[0][1] == 'X' || board[2][1] == 'X' ||
                              board[1][0] == 'X' || board[1][2] == 'X')) ||
           (strat == 3)) {
    if (*moves == 1) { // If it is the first move and the play starts on the
                       // edge, the computer should play in the center
      board[1][1] = 'O';
      b.updateBoard(board);
      strat = 3;
    } else if (OCanWin(
                   b)) { // If O can win, then the code should continue (as the
                         // board is already updated in the OCanWin function)
    } else if (XCanWin(
                   b)) { // If X can win, then the code should continue (as the
                         // board is already updated in the XCanWin function)
    } else if ((*moves == 3) && (board[0][1] == 'X' && board[2][1] == 'X') ||
               (board[1][0] == 'X' &&
                board[1][2] ==
                    'X')) { // This else if statement checks if the opponent has
                            // played their second X on the opposite square of
                            // their first X, forming an X-O-X. If this happens,
                            // then the computer can force a win
      board[0][0] = 'O';
      b.updateBoard(board);
    } else { // If the opponent does not form an X-O-X, then the computer should
             // play in the next open spot to force a draw
      nextOpenSpot(b);
    }
  }
}

bool Computer::checkWin(char player, Board &b) {
  vector<vector<char>> board = b.getVector();
  for (int i = 0; i < 3;
       i++) { // This function loops through the board to see if there are any
              // horizontal or vertical 3-in-a-rows
    if ((board[i][0] == player && board[i][1] == player &&
         board[i][2] == player) ||
        (board[0][i] == player && board[1][i] == player &&
         board[2][i] == player)) {
      return true;
    }
  }
  // This function checks if there are any diagonal 3-in-a-rows
  if ((board[0][0] == player && board[1][1] == player &&
       board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player &&
       board[2][0] == player)) {
    return true;
  }

  return false;
}

int Computer::getMoves() { // This accessor just returns move as a pointer so it
                           // can be updated outside of this class
  return *moves;
}
