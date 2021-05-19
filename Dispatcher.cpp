#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

/* Dispatcher Constructor */
Dispatcher::Dispatcher(Board& b, City c): Player(b, c) {
    this->job = "Dispatcher";
}

/** @brief override function: if there's research station in position
 * can fly_direct anywhere no card erase needed
 * else Player::fly_direct function **/
Player& Dispatcher::fly_direct(City c) {
    if(position == c){
        throw std::invalid_argument{"You can't fly to your position"};
    }
    if(board.isReStation(position)) {
        position = c;
        return *this;
    }
    return Player::fly_direct(c);
}
