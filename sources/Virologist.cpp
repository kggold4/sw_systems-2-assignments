/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Virologist.hpp"

using namespace pandemic;

namespace pandemic {
    Virologist::Virologist(Board& board, const int city) : Player(board, city) {

    }
    Player& treat(const City city) {
        if(this->board.get_city_cubes(this->city) == 0) {
            throw exception("current city not have disease cubes");
        }
        if(has_cure(CITIES_COLORS[this->city])) {
            remove_all_city_cubes();
        } else {
            decrease_city_cubes();
        }
        return *this;
    }
}
