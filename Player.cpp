#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace std;
using namespace pandemic;

namespace pandemic {
        Player::Player(Board& board, const int city) {
            this->board = board;
            this->current_city = city;
            this->number_of_cards = 0;
            this->number_of_research_station = 0;
        }
        Player::~Player() {}
        Player& Player::drive(const int city) {
            return *this;
        }
        Player& Player::fly_direct(const int city) {
            return *this;
        }
        Player& Player::fly_charter(const int city) {
            return *this;
        }
        Player& Player::fly_shuttle(const int city) {
            return *this;
        }
        Player& Player::bulid() {
            return *this;
        }
        Player& Player::discover_cure(const int color) {
            return *this;
        }
        Player& Player::treat(const int city) {
            return *this;
        }
        Player& Player::take_card(const int city) {
            return *this;
        }
        Player& Player::remove_cards() {
            return *this;
        }
        string Player::role() const {
            return typeid(this).name();
        }
}
