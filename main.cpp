#include <iostream>

#include "GameBoard.h"
#include "Player.h"

#include "Player_unittest.h"
#include "Game_unittest.h"

using namespace std;

int main()
{
    cout << "Testing player movements... ";

    Player_unittest test1;
    bool result1 = test1.run();

    if(result1) cout << "success";
    else cout << "fail!";

    cout << endl;

    cout << "Testing game players and game rounds... ";
    Game_unittest test2;
    bool result2 = test2.run();

    if(result2) cout << "success";
    else cout << "fail!";

    cout << endl;

    return 0;
}
