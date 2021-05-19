#include "Medic.hpp"

using namespace std;
using namespace pandemic;

/* Medic Constructor */
Medic::Medic(Board& b, City c): Player(b, c){
    this->job = "Medic";
}

Player& Medic::treat(City c) {
    if(position != c) {
        throw std::invalid_argument{"Treat allows only in your position" + cityToString(c)};
    }
    if(board[c] == 0) {
        throw std::invalid_argument{"You cant treat when disease level is zero"};
    }
    board[c] = 0;
    return *this;
}

Player& Medic::drive(City c){
    Player::drive(c);
    if(board.isCured(Board::getColor(c))) {
        board[c] = 0;
    }
    return *this;

}
Player& Medic::fly_direct(City c) {
    Player::fly_direct(c);
    if(board.isCured(Board::getColor(c))) {
        board[c] = 0;
    }
    return *this;

}
Player& Medic::fly_charter(City c){
    Player::fly_charter(c);
    if(board.isCured(Board::getColor(c))){
        board[c] = 0;
    }
    return *this;
}
Player& Medic::fly_shuttle(City c){
    Player::fly_shuttle(c);
    if(board.isCured(Board::getColor(c))){
        board[c] = 0;
    }
    return *this;
}
