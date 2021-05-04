#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

using namespace std;
using namespace pandemic;

namespace pandemic {
        Player::Player(Board& board, const int city) {
            this->current_city = city;
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
        string Player::role() {
            return "";
        }
}
