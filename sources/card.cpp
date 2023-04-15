#ifndef card_cpp
#define card_cpp
#include "card.hpp"
#include "string"
using namespace std;
using namespace ariel;

Card::Card(int xcard , string ycard){
        this->value = xcard;
        this->sigen = ycard;  
}

int Card::getvalue(){
        return value;
    }

string Card::getsigen(){
        return sigen;
    }

string Card::card_tostring(){
        if(this->value == 1){
            return "played Ace of" + this->sigen;
        }
        if(this->value == 11){
            return "played Jack of" + this->sigen;
        }
        if(this->value == 12){
            return "played Queen of" + this->sigen;
        }
        if(this->value == 13){
            return "played King of" + this->sigen;
        }
        return "played" + std::to_string(this->value) + "of" + this->sigen;
    }

#endif