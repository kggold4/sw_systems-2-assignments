
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

const static unsigned int MAX_REMOVE_CARDS_IN_DISCOVER_CURE = 5;

namespace pandemic {

    GeneSplicer::GeneSplicer(Board& board, const City city) : Player(board, city) { this->role_type="GeneSplicer"; }
    Player& GeneSplicer::discover_cure(const Color color) {

        if(!this->board.has_research_station(this->current_city)) { throw ("current city do not have research station"); }

        bool has_enough_cards = this->player_cards.size() >= MAX_REMOVE_CARDS_IN_DISCOVER_CURE;
        if(!has_enough_cards) { throw ("not enough cards with given color"); }

        // have enough cards with given color
        // removing cards with given color
        int counter_remove_cards = 0;
        set<City>::iterator it = this->player_cards.begin();
        while(it != this->player_cards.end()) {
            it = this->player_cards.erase(it);
            counter_remove_cards++;
            if (counter_remove_cards == MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
                break;
            }
            it++;
        }
        this->board.set_cure(color);
        return *this;
    }

}
