#ifndef PLAYER_UNITTEST_H
#define PLAYER_UNITTEST_H

#include <assert.h>
#include "Player.h"


class Player_unittest
{
    public:
        Player_unittest() {}
        ~Player_unittest() {}

        bool run();

    protected:

    private:
        bool player_rolls_seven();
        bool player_on_thirtynine_rolls_six_and_should_end_up_in_five();
};

#endif // PLAYER_UNITTEST_H
