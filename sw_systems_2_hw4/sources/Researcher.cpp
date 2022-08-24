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
#include "Researcher.hpp"

using namespace pandemic;

const static unsigned int MAX_REMOVE_CARDS_IN_DISCOVER_CURE = 5;

namespace pandemic {

    Researcher::Researcher(Board& board, const City city) : Player(board, city) { this->role_type="Researcher"; }
    Player& Researcher::discover_cure(const Color color) {

        // checking if there enough cards with given color
        bool has_enough_cards = false;
        int counter_colors = 0;
        for(const auto &card : this->player_cards) {
            if(get_city_color(card) == color) {
                counter_colors++;
            }
        }

        if(counter_colors >= MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
            has_enough_cards = true;
        }

        // not have enough cards with given color
        if(!has_enough_cards) { throw ("not enough cards with given color"); }

        // have enough cards with given color
        // removing cards with given color
        int counter_remove_cards = 0;
        set<City>::iterator it = this->player_cards.begin();
        while(it != this->player_cards.end()) {
            if(get_city_color(*it) == color) {
                it = this->player_cards.erase(it);
                counter_remove_cards++;
                if(counter_remove_cards == MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
                    break;
                }
            } else {
                it++;
            }
        }

        this->board.set_cure(color);
        return *this;
    }
}
