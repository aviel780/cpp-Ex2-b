#include<iostream>
#include "game.hpp"
#include "card.cpp"
#include <algorithm>
#include <random>
using namespace ariel;
using namespace std;

namespace ariel
{   Player p1;
    Player p2;
    string lasturn;

    Game::Game(Player playe1, Player playe2)
    :player1(playe1), player2(playe2){

         vector<card> pack(52);
        for (int i = 1; i <= 13; i++)
        {
            pack.push_back(card(i, "clubs"));
            pack.push_back(card(i, "diamonds"));
            pack.push_back(card(i, "hearts"));
            pack.push_back(card(i, "spades"));
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(pack.begin(), pack.end(), g);

        for (int i = 0; i < 52; i= i+2)
        {
            player1.addcard(pack[(unsigned int)i]);
        }

        for (int i = 1; i <= 52; i= i+2)
        {
            player2.addcard(pack[(unsigned int)i]);
        }}


    

    void Game::playTurn(){
        string winner = "";
        int num_of_cards= 2;
        card cp1 = p1.takecard();
        card cp2 = p2.takecard();
        if (cp1.getsigen() == "over")
        {
            printWiner();
            
        }
        if (cp2.getsigen() == "over"){
            
            printWiner();}
            
        
        //Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
        if (cp1.getvalue() > cp2.getvalue()){
            winner = p1.getName();
            p1.setcardstaken(num_of_cards);
        }
        if (cp2.getvalue() > cp1.getvalue()){
            winner = p2.getName();
            p2.setcardstaken(num_of_cards);
        }
        while (cp1.getvalue() == cp2.getvalue())
        {
            winner = "draw";
            p1.takecard();
            p2.takecard();
            card cp1 = p1.takecard();
            card cp2 = p2.takecard();
            lasturn = lasturn + p1.getName() + cp1.card_tostring() + p2.getName()+cp2.card_tostring() + winner;
            num_of_cards += 2 ;

            if (cp1.getvalue() > cp2.getvalue()){
            winner = p1.getName();
            p1.setcardstaken(num_of_cards);
        }
        if (cp2.getvalue() > cp1.getvalue()){
            winner = p2.getName();
            p2.setcardstaken(num_of_cards);
        }
            
        }
        
        lasturn = p1.getName() + cp1.card_tostring() + p2.getName()+cp2.card_tostring() + winner;

    }
    void Game::printLastTurn(){
        cout<<lasturn<<endl;
    }
    void Game::playAll(){}
    void Game::printWiner(){
        if (p1.cardesTaken() > p2.cardesTaken())
        {
            cout<< p1.getName() + "won the game"<<endl;
        }
        if (p2.cardesTaken() > p1.cardesTaken())
        {
            cout<< p2.getName() + "won the game"<<endl;
        }
        if (p1.cardesTaken() == p2.cardesTaken())
        {
            cout<<"draw betwwen" + p1.getName() +"and" +p2.getName() <<endl;
        }
        
    }
    void Game::printLog(){}
    void Game::printStats(){}
    

}; // namespace ariel