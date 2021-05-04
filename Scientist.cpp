
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Scientist.hpp"

using namespace pandemic;

static const int DEFAULT_N = 5;

namespace pandemic {
    Scientist::Scientist(Board& board, const int city, const int n = DEFAULT_N) : Player(board, city) {
        this->n = n;
    }
}
