#include "Game.h"
#include <iostream>

int main()
{
    Game game{};

    int userInput{};

    std::cout << "Please press 1 to play with a human, press 2 to play with "
                 "computer: ";

    std::cin >> userInput;

    switch (userInput)
    {
    case 1:
        game.playerWithHuman();
    case 2:
        game.playerWithComputer();
    }

    return 0;
}
