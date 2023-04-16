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
    vector<Card> cards;
    int cardes_Taken;
    // int id ;
    int cardsWon ;
    int numwingames ;
    int numdrawgames ;
    

    public:


        Player(std::string name);

        std::string getName();

        void setcardstaken(int atake);
        void setwingames(int atake);
        void setdrawgames(int atake);

        int getcardstaken();
        int getwingames();
        int getdrawgames();
        

        int stacksize();

        int cardesTaken();

        void addcard(Card ccard);  

        Card takecard(); 

};
}
#endif //Player_hpp