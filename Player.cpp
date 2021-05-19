#include "Player.hpp"

using namespace std;
using namespace pandemic;
const int NUM_CARDS = 5;

/** @brief change city position to c if c is linked else throw exp **/
Player& Player::drive(City c) {
    if(position == c) {
        throw std::invalid_argument{"You can't drive to your position"};
    }
    if(!Board::isConnected(position, c)) {
        throw std::invalid_argument{"There's no straight road between this cities"};
    }
    position = c;
    return *this;
}

/** @brief change city position to c if card c exists and erase it
 * else throw exp **/
Player& Player:: fly_direct(City c) {
    if(position == c) {
        throw std::invalid_argument{"You can't fly to your position"};
    }
    if(cards.count(c) == 0) {
        throw std::invalid_argument{"You don't have right card"};
    }
    position = c;
    cards.erase(c);
    return *this;
}

/** @brief change city position to c if position card exists and erase it
 * else throw exp **/
Player& Player::fly_charter(City c) {
    if(position == c){
        throw std::invalid_argument{"You can't fly to your position"};
    }
    if(cards.count(position) == 0) {
        throw std::invalid_argument{"You don't have right card"};
    }
    cards.erase(position);
    position = c;
    return *this;
}

/** @brief change city position to c if c and position have research stations
 * else throw exp **/
Player& Player::fly_shuttle(City c) {
    if(position == c){
        throw std::invalid_argument{"You can't fly to your position"};
    }
    if(!(board.isReStation(position) && board.isReStation(c))){
        throw std::invalid_argument{"One city or more have no research station"};
    }
    position = c;
    return *this;
}

/** @brief build research station in city position and erase position card only if exists
 * else do nothing **/
Player& Player::build() {
    if(cards.count(position) == 0) {
        throw std::invalid_argument{"You don't have right card"};
    }
    if(!board.isReStation(position)) {
        board.buildReStation(position);
        cards.erase(position);
    }
    return *this;
}
/** @brief add cure to position color only if research station exist and player have five cards same color of position
 * erase player five cards
 * else throw exp **/
Player& Player:: discover_cure(Color x) {
    if(!board.isCured(x)){
        if(!board.isReStation(position)) {
            throw std::invalid_argument{"City have no research station"};
        }
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
        while(runner != cards.end() && sameColor > 0) {
            if(Board::getColor(*runner) == x) {
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

/** @brief If there is no cure for position color reduce disease level in position by one and erase card
 * if there is cure reduce to zero and erase card
 * if already zero throw exp **/
Player& Player::treat(City c) {
    if(position != c) {
        throw std::invalid_argument{"Treat allows only in your position"};
    }
    if(board[c] == 0) {
        throw std::invalid_argument{"You cant treat when disease level is zero"};
    }
    if(board.isCured(Board::getColor(c))) {
        board[c] = 0;
    }
    else{
        board[c]--;
    }
    return *this;
}

/** @brief insert new card c to cards **/
Player& Player::take_card(City c) {
    cards.insert(c);
    return *this;
}