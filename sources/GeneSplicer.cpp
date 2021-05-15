
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
#include "GeneSplicer.hpp"

using namespace pandemic;

const static unsigned in MAX_REMOVE_CARDS_IN_DISCOVER_CURE = 5;

namespace pandemic {
    GeneSplicer::GeneSplicer(Board& board, const int city) : Player(board, city) {
        
    }
    Player& GeneSplicer::discover_cure(const Color color) override {
        if(!has_research_station(this->current_city)) { throw exception("current city do not have research station"); }
        if(!this->curves.find(color)->second) {

            // checking if there enough cards with given color
            bool has_enough_cards = this->player_cards.size() >= MAX_REMOVE_CARDS_IN_DISCOVER_CURE;

            // not have enough cards with given color
            if(!has_enough_cards) { throw exception("not enough cards with given color"); }

            // have enough cards with given color
            // removing cards with given color
            int counter_remove_cards = 0;
            for(auto &card : this->player_cards) {
                this->player_cards.erase(card);
                counter_remove_cards++;
                if (counter_remove_cards == MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
                    break;
                }
            }
            this->curves.find(color)->second = true;
        }
        return *this;
    }
}
