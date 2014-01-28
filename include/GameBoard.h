#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <Board.h>


class GameBoard : public Board
{
    public:
        explicit GameBoard(int n_cells = 40);
        virtual ~GameBoard();

    protected:

    private:
};

#endif // GAMEBOARD_H
