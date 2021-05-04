
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Dispatcher.hpp"

using namespace pandemic;

namespace pandemic {
    Dispatcher::Dispatcher(Board& board, const int city) : Player(board, city) {
        
    }
}
