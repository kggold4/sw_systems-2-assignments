/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Virologist.hpp"

using namespace pandemic;

namespace pandemic {

    Virologist::Virologist(Board& board, const City city) : Player(board, city) { this->role_type="Virologist"; }
    Player& Virologist::treat(const City city) {
        if(city != this->current_city) {
            if(!has_card(city)) {
                throw invalid_argument("player do not have given city card: " + get_city_name(city));
            }
//            this->player_cards.erase(city);
            remove_card(city);
        }
        if(this->board[city] == 0) { throw invalid_argument("current city not have disease cubes"); }
        if(this->board.has_cure(get_city_color(city))) {
            this->board[city] = 0;
        } else {
            this->board[city]--;
        }
        return *this;
    }
}
