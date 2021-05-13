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
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Player {
        private:

            // player board
            Board board;

            // player current city
            City current_city;

            // player set of cards
            set<City> player_cards;

            // each city can have a research station
            map<City, bool> research_stations;

            // curves discovered
            map<Color, bool> curves;

            // check if city is valid
            bool valid_city(const City city) const {
                if(city < 0 || city >= MAX_CITIES) { return false; }
                return true;
            }
        public:

            // constructor
            Player(Board& board, const City city);

            // de-constructor
            ~Player();

            // drive to given near city (if not near throw exception)
            virtual Player& drive(const City city);

            // fly to another city
            virtual Player& fly_direct(const City city);
            virtual Player& fly_charter(const City city);
            virtual Player& fly_shuttle(const City city);
            virtual Player& build();
            virtual Player& discover_cure(const Color color);
            virtual Player& treat(const City city);
            virtual Player& take_card(const City city);
            virtual Player& remove_cards();
            string role() const;
    };
}
