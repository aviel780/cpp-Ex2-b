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
    Player &p1;
    Player &p2;
    string lasturn;
    string log;

    public:
        Game(Player& player1, Player& player2);

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();



};
}
#endif //Game_hpp