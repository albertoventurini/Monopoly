#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"

using namespace std;

// Interface of Board
//
// Board is a class that contains a vector of cells and supports the following operations:
//   - given a cell and an increment, advance to another cell
//   - given a cell, return its position in the board
//   - get the initial cell
//


class Board
{
        // Constructor / destructor
        // (protected because clients should not instantiate this class directly)
    protected:
        explicit Board(int n_cells);
        virtual ~Board();

    private:
        // List of cells
        vector<Cell* > cells;

    public:
        Cell* advance(Cell* current, int increment);
        Cell* start() { return cells[0]; }
        int getCellPosition(Cell *cell);
};

#endif // BOARD_H
