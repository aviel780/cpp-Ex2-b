#ifndef Card_hpp
#define Card_cpp
#include <iostream>

#include "string"
using namespace std;
namespace ariel
{
class card{
    int value;
    std::string sigen;

    public:

    card(int x , string y){
        value = x;
        sigen = y;  
    }

    ~card();

    int getvalue(){
        return value;
    }

    string getsigen(){
        return sigen;
    }
    string card_tostring(){
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
};



 }

#endif