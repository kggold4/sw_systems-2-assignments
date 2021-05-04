#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    Board::Board() {}
    Board::~Board() {}

    bool Board::is_clean() {
        return false;
    }

    void Board::remove_cures() {

    }
    
    void Board::remove_stations() {

    }

    int& Board::operator[](int city) {
        return T[city];
    }

    ostream& operator<<(ostream& ost, const Board& board) {
        ost << "BOARD";
        return ost;
    }
}
