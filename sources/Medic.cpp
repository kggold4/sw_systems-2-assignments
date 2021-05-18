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
#include "Medic.hpp"

using namespace pandemic;

namespace pandemic {

    Medic::Medic(Board& board, const City city) : Player(board, city) { this->role_type="Medic"; }
    Player& Medic::treat(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(city != this->current_city) { throw invalid_argument("not in given city"); }
        if(this->board[city] == 0) { throw invalid_argument("current city not have disease cubes"); }
        this->board[city] = 0;
        return *this;
    }
}
