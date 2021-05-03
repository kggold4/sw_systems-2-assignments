#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Dispatcher : public Player {
        public:
            Dispatcher(Board& board, const int city);
    };
}