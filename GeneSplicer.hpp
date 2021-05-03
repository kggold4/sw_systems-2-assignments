#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class GeneSplicer : public Player {
        public:
            GeneSplicer(Board& board, const int city);
    };
}