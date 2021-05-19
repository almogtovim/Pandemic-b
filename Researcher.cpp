#include "Researcher.hpp"

const int NUM_CARDS = 5;
using namespace std;
using namespace pandemic;


Researcher::Researcher(Board& b, City c): Player(b, c) {
    this->job = "Researcher";
}

Player& Researcher:: discover_cure(Color x) {
    if(!board.isCured(x)){
        int sameColor = 0;
        for(const auto& card: cards) {
            if(Board::getColor(card) == x) {
                sameColor++;
            }
        }

        if(sameColor < NUM_CARDS){
            throw std::invalid_argument{"Not enough cards"};
        }
        auto runner = cards.begin();
        while(runner != cards.end() && sameColor > 0){
            if(Board::getColor(*runner) == x){
                runner = cards.erase(runner);
                sameColor--;
            }
            else{
                runner++;
            }
            
        }
        board.addCure(x);
    }
    return *this;
}