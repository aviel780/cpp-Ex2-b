#include<iostream>
#include <string>
#include"player.hpp"
#include <vector>
#include"card.hpp"
using namespace std;

namespace ariel{
    
     vector<Card> cards;
  
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

    void Player::setcardstaken(int abc){
        this->cardsWon += abc;

    }

    int Player::stacksize(){
        return cards.size();
    }

    int Player::cardesTaken(){
        return this->cardsWon;
    }

    void Player::addcard(Card carr){
        cards.push_back(carr);
    }

    Card Player::takecard(){
        // if (cards.size() == 0)
        // {
        //     Card win = Card (100,"over");
        //     return win;
        // }
        // else{
        // cout<<stacksize()<<endl;
        Card pick = cards.back();
        cards.pop_back();
        // cout<<pick.getvalue()<<"poping out"<<endl;
        // cout<<stacksize()<<endl;
        
        return pick;
        // }
        
    }

    

} // namespace ariel