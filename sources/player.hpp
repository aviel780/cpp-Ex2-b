#ifndef Player_hpp
#define Player_hpp

#include <string>
#include <stdio.h>
#include <vector>
#include"card.hpp"


namespace ariel{



class Player{
    private:

    string name;
    vector<card> cards;
    int cardes_Taken;
    int id ;
    int cardsWon ;
    int numwingames ;
    int numdraw ;
    int numgames ;

    public:

        
        Player(std::string name);

        std::string getName();

        int stacksize();

        int cardesTaken();

        void addcard(card c);  

        card takecard(); 

};
}
#endif //Player_hpp