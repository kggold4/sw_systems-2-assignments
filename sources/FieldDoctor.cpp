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

    FieldDoctor::FieldDoctor(Board& board, const City city) : Player(board, city) { this->role_type="FieldDoctor"; }
    Player& FieldDoctor::treat(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(city != this->current_city && !is_connected_cities(this->current_city, city)) {
            throw invalid_argument("not in given city");
        }
        if(this->board[city] == 0) { throw invalid_argument("given city not have disease cubes"); }
        if(this->board.has_cure(get_city_color(city))) {
            this->board[city] = 0;
        }
        else {
            this->board[city]--;
        }
        return *this;
    }
}
