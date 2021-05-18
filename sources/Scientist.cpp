
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
#include "Scientist.hpp"

using namespace pandemic;

static const int DEFAULT_N = 4;

namespace pandemic {

    Scientist::Scientist(Board& board, const City city, const int n = DEFAULT_N) : Player(board, city) {
        this->role_type="Scientist";
        this->n = n;
    }
    Player& Scientist::discover_cure(const Color color) {
        if(!this->board.has_research_station(this->current_city)) {
            throw invalid_argument("current city do not have research station");
        }

        // checking if there enough cards with given color
        bool has_enough_cards = false;
        int counter_colors = 0;
        for(auto &card : this->player_cards) {
            if(get_city_color(card) == color) {
                counter_colors++;
            }
        }

        if(counter_colors >= DEFAULT_N) {
            has_enough_cards = true;
        }

        // not have enough cards with given color
        //if(!has_enough_cards) { throw ("not enough cards with given color"); }

        // have enough cards with given color
        // removing cards with given color
        int counter_remove_cards = 0;
        for(auto &card : this->player_cards) {
            if(get_city_color(card) == color) {
                remove_card(card);
                counter_remove_cards++;
                if(counter_remove_cards == DEFAULT_N) {
                    break;
                }
            }
        }
        this->board.set_cure(color);
        return *this;
    }
}
