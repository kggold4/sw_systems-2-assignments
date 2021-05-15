
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
#include "Dispatcher.hpp"

using namespace pandemic;

namespace pandemic {
    Dispatcher::Dispatcher(Board& board, const int city) : Player(board, city) {
        
    }
    Player& Dispatcher::fly_direct(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(city)) { throw invalid_argument("player do not have given city card"); }
        this->current_city = city;
        return *this;
    }
}
