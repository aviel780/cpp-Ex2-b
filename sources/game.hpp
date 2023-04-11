#ifndef Game_hpp
#define Game_hpp

#include <string>
#include <stdio.h>
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
class Game{
    private:
    Player player1;
    Player player2;

    public:
        Game(Player player1, Player player2);

        void playTurn();
        void printLastTurn();
        void playAll();
        void Game::printWiner();
        void printLog();
        void printStats();



};
}
#endif //Game_hpp