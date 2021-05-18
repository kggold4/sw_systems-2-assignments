
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
    Dispatcher::Dispatcher(Board& board, const City city) : Player(board, city) { this->role_type="Dispatcher"; }
    Player& Dispatcher::fly_direct(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(this->current_city == city) { throw invalid_argument("cannot drive to same city: " + get_city_name(city)); }
        if(this->board.has_research_station(this->current_city)) {
            this->current_city = city;
            return *this;
        }
        return Player::fly_direct(city);
    }
}
