#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>


namespace pandemic{
    class Player{
       
        protected:
            Board& board;
            City position;
            std::set<City> cards;
            std::string job;

        public:
            Player(Board& b, City c): board(b), position(c){}
            virtual Player& drive(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color x);
            virtual Player& treat(City c);
            std::string role(){return job;}
            Player& take_card(City c);
            void remove_cards(){cards.clear();};
    };
}