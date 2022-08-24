/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Dispatcher : public Player {
        public:
            Dispatcher(Board& board, const City city);
            Player& fly_direct(const City city) override;
            //Dispatcher& operator=(const Player& player) { return *this; }
    };
}
