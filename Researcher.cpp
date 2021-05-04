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
#include "Researcher.hpp"

using namespace pandemic;

namespace pandemic {
    Researcher::Researcher(Board& board, const int city) : Player(board, city) {
        
    }
}
