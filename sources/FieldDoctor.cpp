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
#include "FieldDoctor.hpp"

using namespace pandemic;

namespace pandemic {
    FieldDoctor::FieldDoctor(Board& board, const int city) : Player(board, city) {
        
    }
    Player& FieldDoctor::treat(const City city) override {
        if(this->board.get_city_cubes(city) == 0) {
            throw exception("given city not have disease cubes");
        }
        if(has_cure(CITIES_COLORS[city])) {
            remove_all_city_cubes();
        } else {
            decrease_city_cubes();
        }
        return *this;
    }
}
