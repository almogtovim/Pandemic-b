#include "Board.hpp"

using namespace std;
using namespace pandemic;


Color Board::getColor(City c) {
    return cityColorMap.at(c);
}

 /** @brief Return true if board is clean [no cube disease] **/
bool Board::is_clean() {
    for(auto& city: cubes) {
        if(city.second > 0) { return false; }
    }
    return true;
}

/** @brief Remove all cures in board [no exp throw] **/
void Board::remove_cures(){
    cured.clear();
}

/** @brief Remove all research stations in board [no exp throw] **/
void Board::remove_stations(){
    reStations.clear();
}

/** @brief Return true if two cities are connected **/
bool Board::isConnected(City& c1, City&c2){
    return (linkedCities.at(c1).count(c2) != 0);
}

/** @brief Build a new research station in city c **/
void Board::buildReStation(City c) {
    reStations.insert(c);
}

/** @brief Return true if there's a research station in city c **/
bool Board::isReStation(City c) {
    return (reStations.count(c)!=0);
}

/** @brief Insert cure to color c **/
void Board::addCure(Color x) {
    cured.insert(x);
}

/** @brief Return true if there's a cure to color c **/
bool Board::isCured(Color x) {
    return (cured.count(x) != 0);
}

/**
 * @brief Return ostream reference template as:
 *
**/

std::ostream& pandemic::operator<<(std::ostream& os, const Board& b) {

    os << "level of disease:" << endl;
    for(const auto& e: b.cubes) {
        os << "\t" << cityToString(e.first) << ": \t\t" << e.second << std::endl;
    }
    os  << "Cure discovered for colors:" << endl;
    for(const auto& c: b.cured) {
        os << "\t" << colorToStr(c) << std::endl;
    }
    os << "Research stations:" << std::endl;
    for(const auto& s: b.reStations) {
        os << "\t" << cityToString(s) << std::endl;
    }
   
    return os;
}

/** @brief OPERATOR [] TO INSERT/PRINT DISEASE LEVEL IN CITY  **/
int& Board::operator[](City c){
    return cubes[c];
}

 std::map<City, std::set<City>> Board::linkedCities {
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei, Manila} },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};