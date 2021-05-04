
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Scientist.hpp"

using namespace pandemic;

namespace pandemic {
    Scientist::Scientist(Board& board, const int city) : Player(board, city) {
        this->n = 5;
    }
    Scientist::Scientist(Board& board, const int city, const int n) : Player(board, city) {
        this->n = n;
    }
}
