#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Scientist : public Player {
        private:
            int n;
        public:
            Scientist(Board& board, const int city);
            Scientist(Board& board, const int city, int n);
            Scientist& build();
    };
}
