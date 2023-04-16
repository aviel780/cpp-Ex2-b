#include<iostream>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <algorithm>
#include <random>
using namespace ariel;
using namespace std;

namespace ariel
{   

    Game::Game(Player &play1, Player &play2) : p1(play1), p2(play2){
    

         vector<Card> pack;
        for (int i = 1; i <= 13; i++)
        {
            pack.push_back(Card(i,"clubs"));
            pack.push_back(Card(i,"diamonds"));
            pack.push_back(Card(i,"hearts"));
            pack.push_back(Card(i,"spades"));
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(pack.begin(), pack.end(), g);

        for (int i = 0; i < 52; i= i+2)
        {
            p1.addcard(pack[(unsigned int)i]);
        }

        for (int i = 1; i <= 52; i= i+2)
        {
            p2.addcard(pack[(unsigned int)i]);
        }}


    void Game::playTurn(){
        if (&p1 == &p2)
        {
            throw "palyer cnot play aginst him self";
        }
        
        if (p1.stacksize() ==0|| p2.stacksize()==0)
        {
            throw "game over - no more cards";
        }
        
        string lasturn = "";
        string winner = "";
        int num_of_cards= 2;
        Card cp1 = p1.takecard();
        Card cp2 = p2.takecard();
        // cout<<cp1.getvalue()<<"!!!!"<<cp2.getvalue()<<endl;
        // if (cp1.getsigen() == "over")
        // {
        //     printWiner();
        //     return;
            
        // }
        // if (cp2.getsigen() == "over"){
            
        //     printWiner();
        //     return;}
        if (cp1.getvalue() > cp2.getvalue()){
            winner = p1.getName();
            p1.setcardstaken(num_of_cards);
            p1.setwingames(1);
        }
        if (cp2.getvalue() > cp1.getvalue()){
            winner = p2.getName();
            p2.setcardstaken(num_of_cards);
            p2.setwingames(1);
        }
        while (cp1.getvalue() == cp2.getvalue())
        {
            // if(p1.stacksize() ==0 ||p2.stacksize() == 0){
            //     return;
            // }
            winner = "draw";
            p1.takecard();
            p2.takecard();
            cp1 = p1.takecard();
            cp2 = p2.takecard();
            p1.setdrawgames(1);
            p2.setdrawgames(1);
            lasturn = lasturn+ " " + p1.getName()+ " " + cp1.card_tostring() + p2.getName()+ " "+cp2.card_tostring() +" " +  winner + " win the war ";
            log+= lasturn;
            num_of_cards += 4 ;

            if (cp1.getvalue() > cp2.getvalue()){
            winner = p1.getName();
            p1.setcardstaken(num_of_cards);
        }
        if (cp2.getvalue() > cp1.getvalue()){
            winner = p2.getName();
            p2.setcardstaken(num_of_cards);
        }
            
        }
        
        lasturn = p1.getName()+ " " + cp1.card_tostring() + p2.getName()+ " "+cp2.card_tostring() +" " +  winner + " win the war ";
        log+= lasturn;
    }

    void Game::printLastTurn(){
        cout<<lasturn<<endl;
    }
    void Game::playAll(){
        while (p1.stacksize()>0 ||p2.stacksize()>0)
        {
            playTurn();
        }
        
    }
    void Game::printWiner(){
        if (p1.cardesTaken() > p2.cardesTaken())
        {
            cout<< p1.getName() + " won the game"<<endl;
        }
        if (p2.cardesTaken() > p1.cardesTaken())
        {
            cout<< p2.getName() + " won the game"<<endl;
        }
        if (p1.cardesTaken() == p2.cardesTaken())
        {
            cout<<"draw betwwen " + p1.getName() +" and " +p2.getName() <<endl;
        }
        
    }
    void Game::printLog(){
        cout<<log<<endl;
    }
    void Game::printStats(){
        cout<<p1.getName()<<" win in "<<p1.getwingames()<<" games, win in "<<p1.getcardstaken()<<" cardes and finish in draw in "<<p1.getdrawgames()<<" games"<<endl;
        cout<<p2.getName()<<" win in "<<p2.getwingames()<<" games, win in "<<p2.getcardstaken()<<" cardes and finish in draw in "<<p2.getdrawgames()<<" games"<<endl;
    }
    

}; // namespace ariel