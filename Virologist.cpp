#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Virologist::Virologist(Board& b, City c): Player(b, c) {
    this->job = "Virologist";
}

Player& Virologist:: treat(City c) {
    if(cards.count(c) == 0 && position != c) {
        throw std::invalid_argument{"No right card"};
    }
    if(board[c] == 0){
        throw std::invalid_argument{"You cant treat when disease level is zero"};
    }
    if(board.isCured(Board::getColor(c))){
        board[c] = 0;
    }
    else{
        board[c]--;
    }
    return *this;
}