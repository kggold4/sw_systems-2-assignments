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
#include "OperationsExpert.hpp"

using namespace pandemic;

namespace pandemic {
    OperationsExpert::OperationsExpert(Board& board, const int city): Player(board, city) {
        
    }
    OperationsExpert& OperationsExpert::build() {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(this->current_city)) { throw invalid_argument("player do not have given city card"); }
        this->research_stations.find(this->current_city)->second = true;
        return *this;
    }
}
