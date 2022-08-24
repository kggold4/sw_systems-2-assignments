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
    OperationsExpert::OperationsExpert(Board& board, const City city): Player(board, city) {
        this->role_type="OperationsExpert";
    }
    Player& OperationsExpert::build() {
        this->board.set_research_station(this->current_city);
        return *this;
    }
}
