#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Scientist::Scientist(Board& b, City c, int num): Player(b, c), n(num){
    this->job = "Scientist";
}

Player& Scientist:: discover_cure(Color c){
    int sameColor = 0;
    if(!board.isCured(c)){
        if(!board.isReStation(position)){
            throw std::invalid_argument{"City have no research station"};
        }
        for(const auto& card: cards){
            if(Board::getColor(card) == c){
                sameColor++;
            }
        }

        if(sameColor < this->n){
            throw std::invalid_argument{"Not enough cards"};
        }
        auto runner = cards.begin();
        while(runner != cards.end() && sameColor > 0){
            if(Board::getColor(*runner) == c){
                runner = cards.erase(runner);
                sameColor--;
            }
            else{
                runner++;
            }
        }
        board.addCure(c);
    }
    return *this;
}