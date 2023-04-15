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
        this->numdrawgames = 0;
        
        
    }

    std::string Player::getName(){
        return this->name;
    }

    void Player::setcardstaken(int abc){
        this->cardsWon += abc;

    }
    void Player::setwingames(int win){
        this->numwingames+= win;
    }

    void Player::setdrawgames(int draw){
        this->numdrawgames+= draw;
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
    int Player::getcardstaken(){
        return cardsWon;
    }
    int Player::getwingames(){
        return numwingames;
    }
    int Player::getdrawgames(){
        return numdrawgames;
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