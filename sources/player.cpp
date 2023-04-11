#include<iostream>
#include <string>
#include"player.hpp"
#include <vector>
#include"card.hpp"
using namespace std;

namespace ariel{
    
     vector<card> cards(26);
  
    Player::Player(std::string n){
        this->name = n;
        this->id = id+1;
        this->cardsWon=0;
        this->numwingames =0;
        this->numdraw = 0;
        this->numgames = 0;
        
    }

    std::string Player::getName(){
        return this->name;
    }

    int Player::stacksize(){
        return cards.size();
    }

    int Player::cardesTaken(){
        return this->cardsWon;
    }

    void addcard(card c){
        cards.push_back(c);
    }

    card takecard(){
        if (cards.size() == 0)
        {
            card win = card (100,"over");
            return win;
        }
        else{
            card pick = cards.back();
            cards.pop_back();
            return pick;
        }
        
    }

} // namespace arielbash