#include "Board.h"    // Include Board class definition
#include "Computer.h" // Include Computer class definition
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int moves = 0; // Initialize moves count
int *ptr = &moves;
Computer comp(ptr);                                // Create Computer object
Board b = Board();                                 // Create Board object
vector<vector<char>> currentBoard = b.getVector(); // Get current board state

// Main function
int main() {
  b.displayBoard();   // Display initial board
  while (moves < 9) { // Loop until moves reach 9
    char x, y;
    cout << "=======================================" << endl;
    cout << "Row and column go from 0 -> 2. Enter your move (row column): ";
    cin >> x >> y; // Asks the user for their move
    int intx = static_cast<int>(x);
    int inty = static_cast<int>(y);
    string extra;
    while ((!isdigit(x) || !isdigit(y) || intx < 48 || intx > 50 || inty < 48 ||
            inty > 50 ||
            currentBoard[intx - 48][inty - 48] !=
                ' ')) { // Checks for invalid inputs
      getline(cin, extra);
      cout << "Invalid move. Try again." << endl;
      cout << "Enter your move (row column): ";
      cin >> x >> y;
      intx = static_cast<int>(x);
      inty = static_cast<int>(y);
    }
    getline(cin, extra);
    currentBoard[intx - 48][inty - 48] = 'X';
    b.updateBoard(currentBoard); // Update board with player's move
    moves++;                     // Increment moves count

    cout << "=======================================" << endl;
    cout << "Your move:" << endl;
    b.displayBoard(); // Display board after player's move

    if (comp.winLoseOrDraw(b)) { // Check if player wins, loses, or draw
      break;
    }

    comp.move(b); // Computer makes a move
    currentBoard = b.getVector();
    moves++;
    cout << "=======================================" << endl;
    cout << "Computer's Move: \n";
    b.displayBoard(); // Display board after computer's move

    if (comp.winLoseOrDraw(b)) { // Check if computer wins, loses, or draw
      break;
    }
    cout << endl;
  }
  return 0; // Return 0 upon completion
}
