#ifndef GAME_UNITTEST_H
#define GAME_UNITTEST_H

#include <Game.h>

class Game_unittest
{
    public:
        Game_unittest() {}
        ~Game_unittest() {}

        bool run();

    protected:

    private:
        bool create_a_game_with_two_players();
        bool players_should_not_be_less_than_two_or_more_than_eight();
        bool names_should_be_shuffled();

        bool number_of_played_rounds_should_be_twenty();
        bool order_of_players_should_not_change_at_each_round();
};

#endif // GAME_UNITTEST_H
