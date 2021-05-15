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
    Medic::Medic(Board& board, const int city) : Player(board, city) {
        
    }
    Player& Medic::treat(const City city) {
        if(city != this->current_city) { throw invalid_argument("not in given city"); }
        if(this->board.get_city_cubes(this->current_city) == 0) {
            throw exception("current city not have disease cubes");
        }
        remove_all_city_cubes();
        return *this;
    }
}
