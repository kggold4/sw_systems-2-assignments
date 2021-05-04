#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

static const unsigned int MAX_CITIES = 48;

namespace pandemic {
    Board::Board() {
        for(int i = 0; i < MAX_CITIES; i++) { T[i] = 0; }
    }

    Board::~Board() {}

    bool Board::is_clean() {
        bool ans = true;
        for(int i = 0; i < MAX_CITIES; i++) {
            if(T[i] > 0) {
                ans = false;
                break;
            }
        }
        return ans;
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
