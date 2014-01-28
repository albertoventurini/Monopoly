#include "Player_unittest.h"

#include "FixedDie.h"
#include "Player.h"
#include "GameBoard.h"


bool Player_unittest::player_rolls_seven()
{
    GameBoard gameBoard;
    Player player1("player1", &gameBoard);
    FixedDie die1(7);

    player1.rollDieAndAdvance(die1);
    if(player1.getPosition() != 7) return false;

    return true;
}


bool Player_unittest::player_on_thirtynine_rolls_six_and_should_end_up_in_five()
{
    GameBoard gameBoard;
    Player player2("player2", &gameBoard);
    FixedDie die2(6);

    player2.setPosition(39);
    player2.rollDieAndAdvance(die2);
    if(player2.getPosition() != 5) return false;

    return true;
}


bool Player_unittest::run()
{
    return
        player_rolls_seven() &&
        player_on_thirtynine_rolls_six_and_should_end_up_in_five();
}
