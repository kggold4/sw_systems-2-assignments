#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Medic : public Player {
        public:
            Medic(Board& board, const int city);
            Medic& build();
    };
}
