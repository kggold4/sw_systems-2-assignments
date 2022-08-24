/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

#pragma once

#include <set>
#include <map>
#include "string"
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;

const static unsigned int MAX_CITIES = 48;

namespace pandemic {
    class Player {

        protected:

            // player board
            Board& board;

            // player current city
            City current_city;

            // player set of cards
            set<City> player_cards;

            // role type
            string role_type;

            // return true if the player have the given city card
            bool has_card(City city) {
                if(cards_is_empty()) { throw invalid_argument("player do not have cards"); }
                return this->player_cards.find(city) != this->player_cards.end();
            }

            // remove card from player cards
            void remove_card(City city) { this->player_cards.erase(city); }

            // check if city is valid
            bool valid_city(const City city) const {
                if(city < 0 || city >= MAX_CITIES) { return false; }
                return true;
            }

            bool cards_is_empty() const { return this->player_cards.empty(); }

        public:

            // constructor
            Player(Board& board, const City city);

            // de-constructor
            ~Player();

            // drive to given near city (if not near throw exception)
            Player& drive(const City city);

            // non-override methods
            Player& fly_charter(const City city);
            Player& fly_shuttle(const City city);
            Player& take_card(const City city);

            // override methods
            virtual Player& fly_direct(const City city);
            virtual Player& build();
            virtual Player& discover_cure(const Color color);
            virtual Player& treat(const City city);
            virtual Player& remove_cards();

            Player& operator=(const Player& player) { return *this; }

//            Player& operator=(Player& player) {
//                this->board = player.board;
//                this->current_city = player.current_city;
//                this->player_cards = player.player_cards;
//                this->role_type = player.role_type;
//                return *this;
//            }

            string role() const;
    };
}
