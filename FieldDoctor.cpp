#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

/* FieldDoctor Constructor */
FieldDoctor::FieldDoctor(Board& b, City c): Player(b, c) {
    this->job = "FieldDoctor";
}

/** @brief override function: can treat also any linked city c no card erase needed
 * else throw exp **/
Player& FieldDoctor::treat(City c) {
    if(!Board::isConnected(position,c) && position != c ) {
        throw std::invalid_argument{"There's no straight road between this cities"};
    }
    if(board[c] == 0) {
        throw std::invalid_argument{"You cant treat when disease level is zero"};
    }
    if(board.isCured(Board::getColor(c))) {
        board[c] = 0;
    }
    else {
        board[c]--;
    }
    return *this;
}