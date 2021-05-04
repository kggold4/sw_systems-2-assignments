
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Medic.hpp"

using namespace pandemic;

namespace pandemic {
    Medic::Medic(Board& board, const int city) : Player(board, city) {
        
    }
}
