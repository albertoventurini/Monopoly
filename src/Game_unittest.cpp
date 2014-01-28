#include <algorithm>
#include <vector>
#include "Game_unittest.h"
#include "Player.h"

using namespace std;


bool Game_unittest::create_a_game_with_two_players()
{
    // Create a game with two players named Horse and Car.
    vector<string> playerNames;

    playerNames.push_back("Horse");
    playerNames.push_back("Car");
    Game game(playerNames);

    // (Just verifying that the names are there)
    vector<string> playerNames2 = game.getPlayerNames();
    if(find(playerNames2.begin(), playerNames2.end(), "Horse") == playerNames2.end())
        return false;
    if(find(playerNames2.begin(), playerNames2.end(), "Car") == playerNames2.end())
        return false;

    return true;
}


bool Game_unittest::players_should_not_be_less_than_two_or_more_than_eight()
{
    // Try to create a game with < 2 or > 8 players. When attempting to play the game, it will fail.
    vector<string> onePlayer;
    onePlayer.push_back("player1");
    Game onePlayerGame(onePlayer);

    try
    {
        onePlayerGame.play();

        // If we reach the following statement, we are failing the test.
        return false;
    }
    catch (const string& s)
    {
    }

    vector<string> ninePlayers;
    for(int i = 0; i < 9; i++)
        ninePlayers.push_back("player");

    Game ninePlayerGame(ninePlayers);

    try
    {
        ninePlayerGame.play();

        // If we reach the following statement, we are failing the test.
        return false;
    }
    catch (const string& s)
    {
    }

    return true;
}


bool Game_unittest::names_should_be_shuffled()
{
    // Create a game with two players named Horse and Car. Within creating 100 games,
    // both orders [Horse, Car] and [car, horse] occur.


    vector<string> playerNames;

    playerNames.push_back("Horse");
    playerNames.push_back("Car");
    Game game(playerNames);

    int status = 0;
    for(int i = 0; i < 100; i++)
    {
        Game game100(playerNames);
        string name1 = game100.getPlayerNames()[0];
        string name2 = game100.getPlayerNames()[1];
        if(name1 == "Horse" && name2 == "Car") status++;
        if(name1 == "Car" && name2 == "Horse") status++;

        if(status == 2) break;
    }

    if(status != 2) return false;

    return true;
}



bool Game_unittest::number_of_played_rounds_should_be_twenty()
{
    vector<string> playerNames;

    playerNames.push_back("Horse");
    playerNames.push_back("Car");
    Game game(playerNames);

    game.play();

    if(game.n_rounds != 20) return false;

    for(auto player : game.players)
        if(player->n_rounds != 20) return false;

    return true;
}


bool Game_unittest::order_of_players_should_not_change_at_each_round()
{
    vector<string> playerNames;

    playerNames.push_back("Horse");
    playerNames.push_back("Car");
    Game game(playerNames);

    string name1 = game.getPlayerNames()[0];
    string name2 = game.getPlayerNames()[1];

    for(int i = 0; i < 20; i++)
    {
        game.playRound();
        if(name1 != game.getPlayerNames()[0]) return false;
        if(name2 != game.getPlayerNames()[1]) return false;
    }

    return true;
}


bool Game_unittest::run()
{
    return
        create_a_game_with_two_players() &&
        players_should_not_be_less_than_two_or_more_than_eight() &&
        names_should_be_shuffled() &&
        number_of_played_rounds_should_be_twenty() &&
        order_of_players_should_not_change_at_each_round();

}
