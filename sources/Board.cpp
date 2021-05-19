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

    // board constructor
    Board::Board() {

        for(int i = 0; i < MAX_CITIES; i++) {
            City city = city_by_index(i);
            this->cities_cubes[city] = 0;
            this->research_stations.insert({city, false});
        }
        for(int i = 0; i < MAX_COLORS; i++) {
            Color color = color_by_index(i);
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

    ostream& operator<<(ostream& out, const Board& board) {

        out << "output";

        for(const auto c: CITIES_MAP) {
            cout << "City: " << get_city_name(c.first) << ", Color: " << get_color_name(c.second) << ",,," << endl;
        }

//        map<City, Color> temp_city_map(CITIES_MAP);
//        map<City, Color>::iterator it = temp_city_map.begin();
//        while(it != CITIES_MAP.end()) {
//            //out << "City: " << it->first << ", Color: " << it->second << ", Number of Disease Cubes: " << board.get_city_cubes(it->first);
//            it++;
//        }
        return out;
    }
}
