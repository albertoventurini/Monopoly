#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "GameBoard.h"
#include "Die.h"

// Interface of Game class
//
// A game supports the following operations:
//  - given a list of player names, create a new game
//  - get the list of player names
//  - play
//

using namespace std;


class Game
{
    public:
        Game(const vector<string>& playerNames);
        ~Game();

        vector<string> getPlayerNames() const;

        void play(); // Play a full game (20 rounds)

    protected:

    private:
        vector<Player *> players;
        GameBoard gameBoard;
        int n_rounds;
        Die die;

        // Play one round
        void playRound();

        // Some constants
        static const int roundsPerGame = 20;
        static const int standardGameBoardSize = 40;
        static const int standardDieFaces = 6;

        friend class Game_unittest;
};

#endif // GAME_H
