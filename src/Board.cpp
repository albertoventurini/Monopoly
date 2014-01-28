#include <algorithm>
#include <iterator>
#include "Board.h"

using namespace std;


// Implementation of Board


Board::Board(int n_cells)
{
    // Initializes all the cells
    for(int i = 0; i < n_cells; i++)
        cells.push_back(new Cell());
}


Board::~Board()
{
    for(size_t i = 0; i < cells.size(); i++)
        delete cells[i];
}


// Given a cell,
// return its position in the board
int Board::getCellPosition(Cell* cell)
{
    for(size_t i = 0; i < cells.size(); i++)
        if(cells[i] == cell) return (int)i;

    throw string("Cell not found!");
}



// Given a cell and an increment (integer),
// return the cell current+increment
Cell* Board::advance(Cell* current, int increment)
{
    int idx = (getCellPosition(current) + increment) % cells.size(); // wrap around the board
    return cells[idx];
}


