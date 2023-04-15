#ifndef card_hpp
#define card_hpp
#include <iostream>
#include "string"
using namespace std;
namespace ariel
{
class Card{
    
    int value;
    std::string sigen;

    public:

    Card(int xcard , string ycard);

    

    int getvalue();
    string getsigen();
    string card_tostring();
};
}
#endif //Card_hpp