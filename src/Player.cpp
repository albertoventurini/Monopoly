#include <iostream>
#include "Player.h"

Player::Player(const string& name, Board* board)
{
    this->name = name;
    this->board = board;
    n_rounds = 0;
    myCell = board->start();
}



int Player::getPosition()
{
    return board->getCellPosition(myCell);
}


void Player::setPosition(int pos)
{
    myCell = board->advance(board->start(), pos);
}


void Player::rollDieAndAdvance(const Die& die)
{
    int advance = die.roll();
    myCell = board->advance(myCell, advance);
}


void Player::playRound(const Die& die)
{
    rollDieAndAdvance(die);

    // TO DO: do some actions here

    n_rounds++;
}
