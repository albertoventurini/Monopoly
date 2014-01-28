#include <algorithm>
#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;


Game::Game(const vector<string>& playerNames) :
    gameBoard(standardGameBoardSize), n_rounds(0), die(standardDieFaces)
{
    for(auto name : playerNames)
         players.push_back(new Player(name, &gameBoard));

    random_shuffle(players.begin(), players.end());
}

Game::~Game()
{
    vector<Player *>::iterator it;
    for(it = players.begin(); it != players.end(); it++)
        delete *it;
}


vector<string> Game::getPlayerNames() const
{
    vector<string> names;

    for(auto player : players)
        names.push_back(player->getName());

    return names;
}


void Game::playRound()
{
    for(auto player : players)
        player->playRound(die);

    n_rounds++;
}


void Game::play()
{
    // Check that the number of players is valid
    if(players.size() < 2 || players.size() > 8)
        throw string("Invalid number of players");

    // Play 20 rounds
    for(int i = 0; i < roundsPerGame; i++)
        playRound();
}
