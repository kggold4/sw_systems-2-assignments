#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Researcher : public Player {
        public:
            Researcher(Board& board, const int city);
            Researcher& build();
    };
}
