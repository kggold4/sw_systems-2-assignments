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

namespace pandemic {

    Player::Player(Board& board, const int city) {
        this->board = board;
        this->current_city = city;
        this->number_of_cards = 0;
        this->number_of_research_station = 0;
    }
    Player::~Player() {}

    Player& Player::drive(const int city) {
        Set<City> close_cities = city_map.at(this->current_city);
        for(auto &i : close_cities) {
            if(i == city) {
                this->current_city = city;
                return *this;
            }
        }
        throw invalid_argument("given city is not close to current city");
    }
    Player& Player::fly_direct(const int city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        this->current_city = city;
        return *this;
    }
    Player& Player::fly_charter(const int city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        this->current_city = city;
        return *this;
    }
    Player& Player::fly_shuttle(const int city) {
        if(!valid_city(city)) { throw invalid_argument("invalid given city - do not exist"); }
        if(!has_station[this->current_city]) {
            throw invalid_argument("current city has no stations");
        } else {
            if(!has_station[city]) {
                throw invalid_argument("given city has no stations");
            } else {
                this->current_city = city;
            }
        }
        return *this;
    }
    Player& Player::build() {
        has_station[this->current_city] = true;
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
