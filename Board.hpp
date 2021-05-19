#pragma once
#include <iostream>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"



namespace pandemic{
    class Board{

        std::map<City, int> cubes;
        std::set<City> reStations;
        std::set<Color> cured;
        static std::map<City, std::set<City>> linkedCities;

        public:
            Board(){}
            bool is_clean();
            bool isReStation(City c);
            bool isCured(Color x);
            void remove_cures();
            void remove_stations();
            void buildReStation(City c);
            void addCure(Color x);
            int& operator[] (City c);
            friend std::ostream& operator<<(std::ostream& os, const Board& b);
            static bool isConnected(City& c1, City& c2);
            static Color getColor(City c);

    };
}