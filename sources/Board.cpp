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
        for(int i = 0; i < MAX_CITIES; i++) {
            this->cities_cubes[i] = 0;
            string name_city = CITIES_NAMES[i];
            this->cities_names[i] = name_city;
            City city = city_by_index_enum(i);
            this->research_stations.insert({city, false});
        }
        for(i = 0; i < MAX_COLORS; i++) {
            Color color = color_by_index_enum(i);
            this->cures.insert({color, false});
        }

    }

    Board::~Board() {}

    bool Board::is_clean() const {
        bool ans = true;
        for(int i = 0; i < MAX_CITIES; i++) {
            if(get_city_cubes(city_by_index_enum(i)) > 0) {
                ans = false;
                break;
            }
        }
        return ans;
    }

    void Board::remove_cures() {

    }
    
    void Board::remove_stations() {

    }

    int& Board::operator[](int city) {
        return cities_cubes[city];
    }

    ostream& operator<<(ostream& ost, const Board& board) {

        for(int i = 0; i < MAX_CITIES; i++) {
            ost << i << " [" << board.get_city_name(city_by_index_enum(i)) << "]: " << board.get_city_cubes(city_by_index_enum(i)) << endl;
        }

        return ost;
    }
}
