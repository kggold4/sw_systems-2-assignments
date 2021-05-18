/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */
#include <set>
#include <map>
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

namespace pandemic {

    // number of cities
    static const unsigned int MAX_CITIES = 48;
    static const unsigned int MAX_COLORS = 4;

    // board constructor
    Board::Board() {
        int i;
        for(i = 0; i < MAX_CITIES; i++) {

            City city = city_by_index_enum(i);
            this->cities_cubes[city] = 0;
            string name_city = CITIES_NAMES[i];
            this->cities_names[i] = name_city;
            this->research_stations.insert({city, false});
        }
        for(i = 0; i < MAX_COLORS; i++) {
            Color color = color_by_index_enum(i);
            this->cures.insert({color, false});
        }

    }

    Board::~Board() {}

    bool Board::is_clean() {
        bool ans = true;
        map<City, int>::iterator it = this->cities_cubes.begin();
        while(it != this->cities_cubes.end()) {
            if(it->second > 0) {
                ans = false;
                break;
            }
            it++;
        }
        return ans;
    }

    void Board::remove_cures() {
        map<Color, bool>::iterator it = this->cures.begin();
        while(it != this->cures.end()) {
            it->second = false;
            it++;
        }
    }
    
    void Board::remove_stations() {
        map<City, bool>::iterator it = this->research_stations.begin();
        while(it != this->research_stations.end()) {
            it->second = false;
            it++;
        }
    }

    int& Board::operator[](City city) {
        return this->cities_cubes[city];
    }

    ostream& operator<<(ostream& ost, const Board& board) {
        for(int i = 0; i < MAX_CITIES; i++) {
            ost << i << " [" << board.get_city_name(city_by_index_enum(i)) << "]: " << board.get_city_cubes(city_by_index_enum(i)) << endl;
        }
        return ost;
    }
}
