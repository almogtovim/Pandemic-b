#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;
const int NUM_CARDS = 5;

/* GeneSplicer Constructor */
GeneSplicer::GeneSplicer(Board& b, City c): Player(b, c) {
    this->job = "GeneSplicer";
}

/** @brief override function: can discover_cure with any five cards
 * else throw exp **/
Player& GeneSplicer:: discover_cure(Color x) {
    if(!board.isCured(x)) {
        if(!board.isReStation(position)) {
            throw std::invalid_argument{"City have no research station"};
        }
        int hand = cards.size();
        if(hand < NUM_CARDS){
            throw std::invalid_argument{"Not enough cards"};
        }
        auto runner = cards.begin();
        int tmp = NUM_CARDS;
        while(runner != cards.end() && tmp > 0) {
            runner = cards.erase(runner);
            tmp--;
            runner++;
        }
        board.addCure(x);
    }
    return *this;
}