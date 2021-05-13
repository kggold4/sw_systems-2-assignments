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

const static unsigned int MAX_CITIES = 48;
const static unsigned int MAX_COLORS = 4;
const static unsigned in MAX_REMOVE_CARDS_IN_DISCOVER_CURE = 5;

namespace pandemic {

    Player::Player(Board& board, const City city) {
        this->board = board;
        this->current_city = city;
    }
    Player::~Player() {}

    Player& Player::drive(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(city)) { throw invalid_argument("player do not have given city card"); }
        Set<City> close_cities = city_map.at(this->current_city);
        for(auto &i : close_cities) {
            if(i == city) {
                this->current_city = city;
                if(rold() == "Medic") { remove_all_city_cubes(); }
                return *this;
            }
        }
        throw invalid_argument("given city is not close to current city");
    }
    Player& Player::fly_direct(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(city)) { throw invalid_argument("player do not have given city card"); }
        this->current_city = city;
        this->player_cards.erase(city);
        if(rold() == "Medic") { remove_all_city_cubes(); }
        return *this;
    }
    Player& Player::fly_charter(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        this->current_city = city;
        this->player_cards.erase(city);
        if(rold() == "Medic") { remove_all_city_cubes(); }
        return *this;
    }
    Player& Player::fly_shuttle(const City city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!this->has_research_station((this->current_city)) {
            throw invalid_argument("current city has no research station");
        } else {
            if(!this->has_research_station(city)) {
                throw invalid_argument("given city has no research station");
            } else {
                this->current_city = city;
            }
        }
        if(rold() == "Medic") { remove_all_city_cubes(); }
        return *this;
    }
    Player& Player::build() {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_card(this->current_city)) { throw invalid_argument("player do not have given city card"); }
        this->player_cards.erase(this->current_city);
        this->research_stations.find(this->current_city)->second = true;
        return *this;
    }
    Player& Player::discover_cure(const Color color) {
        if(!has_research_station(this->current_city)) { throw exception("current city do not have research station"); }
        if(!this->curves.find(color)->second) {

            // checking if there enough cards with given color
            bool has_enough_cards = false;
            int counter_colors = 0;
            for(auto &card : this->player_cards) {
                if(CITIES_COLORS[card] == color) {
                    counter_colors++;
                    if(counter_colors == MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
                        has_enough_cards = true;
                        break;
                    }
                }
            }

            // not have enough cards with given color
            if(!has_enough_cards) { throw exception("not enough cards with given color"); }

            // have enough cards with given color
            // removing cards with given color
            int counter_remove_cards = 0;
            for(auto &card : this->player_cards) {
                if (CITIES_COLORS[card] == color) {
                    this->player_cards.erase(card);
                    counter_remove_cards++;
                    if (counter_remove_cards == MAX_REMOVE_CARDS_IN_DISCOVER_CURE) {
                        break;
                    }
                }
            }
            this->curves.find(color)->second = true;
        }
        return *this;
    }
    Player& Player::treat() {
        if(this->board.get_city_cubes(this->current_city) == 0) {
            throw exception("current city not have disease cubes");
        }
        if(has_cure(CITIES_COLORS[this->current_city])) {
            remove_all_city_cubes();
        } else {
            decrease_city_cubes();
        }
        return *this;
    }
    Player& Player::take_card(const City city) {
        this->cards.insert(City(city));
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
