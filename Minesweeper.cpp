#include "Minesweeper.h"
#include <iostream>
using std::cout;
using std::endl;

// Function: add_mine
// Inputs: board, size, and difficulty (number of mines)
// Outputs: board is filled by reference with mines
void add_mines(int board[], int size, int difficulty) {
  for (int i = 0; i < difficulty; i++) {
    int mine = rand() % size;
    if (board[mine] == MINE) {
      i--;
    } else {
      board[mine] = MINE;
    }
  }
}

// Function: print_board
// Inputs: board, checked array, size (both are same size)
// Outputs: Prints the board out using the GRAPHICS string based on
//          the parallel array checked
void print_board(const int board[], const int checked[], int size) {
  cout << "    0 1 2 3 4 5 6 7" << endl << "-------------------" << endl;

  int board_height;
  int board_width;
  if (size == EASY_SIZE) {
    board_height = 8;
    board_width = 8;
  }
  // This is how you can print a 1D array in 2D.
  // Iterate row by row
  for (int r = 0; r < board_height; r++) {
    // go across the row printing the value in the board
    cout << r << "| ";
    for (int c = 0; c < board_width; c++) {
      // row * maxWidth + col == current index
      int loc = r * board_width + c;
      if (checked[loc] != 0)
        cout << GRAPHICS[board[loc] + 1];
      else
        cout << GRAPHICS[UNCHECKED];
    }
    cout << endl;
  }
}

// Dig at a location (mark the correct spot in checked)
void dig_at_location(int x, int y, int checked[], int size) {
  int board_width;
  if (size == EASY_SIZE) {
    board_width = 8;
  }
  // Location in a 1D array based on 2D (x, y coords)
  int location = y * board_width + x;

  if (!isValidLocation(
          location, size)) { // if the location is invalid just leave/do nothing
    cout << "Invalid location..." << endl; // debugging
    return;
  }
  // check the spot
  checked[location] = 1;
}

// Make sure the location is between 0 and the size of the board inclusive
bool isValidLocation(int location, int size) 
{
	if (location < 0 || location >= size)
	{
		return false;
	}
	else
	{
		return true;
	}
  // if the location is less than 0 or greater than/equal to size
  // return false
  // otherwise return true
}

// Determine if we've lost
bool isLoser(const int board[], const int checked[], int size) 
{
  // For Each spot that has been checked
	for (int i = 0; i < size; i++)
		{
	// if there is a mine in the board there
  // return true (we've lost)
			if (board[i] == MINE && checked[i] == 1)
			{
				return true;
			}
		}
  // otherwise return false
  return false;
}
bool isWinner(const int board[], const int checked[], int size) 
{
	int number = 0;
	int victory = size - 10;
	for (int i = 0; i < size; i++)
		{
			if (board[i] == 0 && checked[i] == 1)
			{
				number++;
			}
		}
	if (number == victory)
	{
		return true;
	}
  // as long as no checked spot contains a mine in the board
  // and the total number of checked spots is equal to the
  // board size - mine count
  // we've won
  // otherwise return false
  return false;
}