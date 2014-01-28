#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"
#include "Cell.h"
#include "Die.h"

using namespace std;


// Interface of Player
//
// The class Player exposes the following operations:
//   - play one round
//   - get current position on the board
//   - set current position on the board
//   - get player's name
//   - set player's name
//

class Player
{
    public:
        // Constructor / destructor
        Player(const string& name, Board* board);
        ~Player() {}

        // Roll a die 'd' and move around the board
        void playRound(const Die& d);

        // Get / set current position
        int getPosition();
        void setPosition(int pos);

        // Get / set name
        string getName() const { return name; }
        void setName(string name) { this->name = name; }

    private:
        string name;
        Cell* myCell;
        Board* board;

        int n_rounds; // number of played rounds

        // Roll a die and advance on the board
        void rollDieAndAdvance(const Die& d);

        friend class Player_unittest;
        friend class Game_unittest;
};

#endif // PLAYER_H
