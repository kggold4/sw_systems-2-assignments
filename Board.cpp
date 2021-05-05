/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

static const unsigned int MAX_CITIES = 48;


namespace pandemic {
    Board::Board() {
        for(int i = 0; i < MAX_CITIES; i++) { cities_cubes[i] = 0; }
        for(int i = 0; i < MAX_CITIES; i++) {
            cities_names[i] = CITIES_NAMES[i];
        }
    }

    Board::~Board() {}

    bool Board::is_clean() {
        bool ans = true;
        for(int i = 0; i < MAX_CITIES; i++) {
            if(cities_cubes[i] > 0) {
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
        // for(auto &v : board.cities_cubes) {
        //     ost << v.first+1 << " [" << CITIES_NAMES[v.first] << "]: " << v.second << endl;
        // }

        for(int i = 0; i < MAX_CITIES; i++) {
            ost << i << " [" << board.get_city_name(i) << "]: " << board.get_city_cubes(i) << endl;
        }
        
        // ost << "size of cities_names is: " << int(CITIES_NAMES->length()) << endl;

        // ost << "cities: " << endl;
        // for(int i = 0; i < 48; i++) {
        //     ost << i << CITIES_NAMES[i] << ", ";
        // }
        ost << endl;

        return ost;
    }
}
