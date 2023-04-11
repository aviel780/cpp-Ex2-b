#ifndef Card_hpp
#define Card_hpp
#include "string"
using namespace std;
namespace ariel
{
class card{
    int value;
    std::string sigen;

    public:

    card(int x , string y);

    ~card();

    int getvalue();
    string getsigen();
     string card_tostring();
};
}
#endif //Card_hpp