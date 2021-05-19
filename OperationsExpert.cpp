#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

/* OperationsExpert Constructor */
OperationsExpert::OperationsExpert(Board& b, City c): Player(b, c) {
    this->job = "OperationsExpert";
}

Player& OperationsExpert::build(){
    board.buildReStation(position);
    return *this;
}