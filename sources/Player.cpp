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

using namespace std;
using namespace pandemic;

const static unsigned int MAX_COLORS = 4;
const static unsigned int MAX_REMOVE_CARDS_IN_DISCOVER_CURE = 5;

namespace pandemic {

    Player::Player(Board& board, const City city) {
        this->board = board;
        this->current_city = city;
    }
    Player::~Player() {}

    Player& Player::drive(const City city) {
        if(this->current_city == city) { throw invalid_argument("cannot drive to same city: " + get_city_name(city)); }
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        set<City> close_cities = city_map.at(city);
        for(auto &i : close_cities) {
            if(i == city) {
                this->current_city = city;
                if(role() == "Medic" && this->board.has_cure(get_city_color(city))) { board[city] = 0; }
                return *this;
            }
        }
        throw invalid_argument("given city " + get_city_name(city) + " is not connection to current city " +
                                       get_city_name(this->current_city));
    }
    Player& Player::fly_direct(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(city)) { throw invalid_argument("player do not have given city card: " + get_city_name(city)); }
        if(this->current_city == city) { throw invalid_argument("cannot drive to same city: " + get_city_name(city)); }
        remove_card(city);
        this->current_city = city;
        if(role() == "Medic" && this->board.has_cure(get_city_color(city))) { board[city] = 0; }
        return *this;
    }
    Player& Player::fly_charter(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(city)) { throw invalid_argument("player do not have given city card"); }
        if(this->current_city == city) { throw invalid_argument("cannot drive to same city: " + get_city_name(city)); }
        remove_card(city);
        this->current_city = city;
        if(role() == "Medic" && this->board.has_cure(get_city_color(city))) { board[city] = 0; }
        return *this;
    }
    Player& Player::fly_shuttle(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!this->board.has_research_station(city)) {
            throw invalid_argument("given city " + get_city_name(city) + " has no research station");
        } else if(!this->board.has_research_station(this->current_city)) {
            throw invalid_argument("current city " + get_city_name(city) + " has no research station");
        } else {
            if(this->current_city == city) { throw invalid_argument("cannot drive to same city: " + get_city_name(city)); }
            this->current_city = city;
            if(role() == "Medic" && this->board.has_cure(get_city_color(city))) { board[city] = 0; }
        }
        return *this;
    }
    Player& Player::build() {
        if(!valid_city(this->get_current_city())) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(this->current_city)) { throw invalid_argument("player do not have given city card"); }
        remove_card(this->current_city);
        this->board.set_research_station(this->current_city);
        return *this;
    }
    Player& Player::discover_cure(const Color color) {
        if(!this->board.has_research_station(this->current_city)) { throw ("current city do not have research station"); }

        // checking if there enough cards with given color
        bool has_enough_cards = false;
        int counter_colors = 0;
        for(auto &card : this->player_cards) {
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
        for(auto &card : this->player_cards) {
            if (get_city_color(color) == color) {
                this->player_cards = this->player_cards.erase(card);
                counter_remove_cards++;
                if (counter_remove_cards == MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
                    break;
                }
            }
        }
        this->board.set_cure(color);
        return *this;
    }

    Player& Player::treat(const City city) {
        if(city != this->current_city) { throw invalid_argument("not in given city"); }
        if(this->board[city] == 0) { throw invalid_argument("current city not have disease cubes"); }
        if(this->board.has_cure(get_city_color(city))) {
            this->board[city] = 0;
        } else {
            this->board[city]--;
        }
        return *this;
    }
    Player& Player::take_card(const City city) {
        this->player_cards.insert(city);
        return *this;
    }
    Player& Player::remove_cards() {
        this->player_cards.clear();
        return *this;
    }
    string Player::role() const {
        return typeid(this).name();
    }
}
