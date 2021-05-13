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
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Player {
        private:
            Board board;
            int current_city;
            unsigned int number_of_cards;
            set<City> cards;
            bool valid_city(const City city) const {
                if(city < 0 || city >= MAX_CITIES) { return false; }
                return true;
            }
        public:
            Player(Board& board, const City city);
            ~Player();

            // drive to given near city (if not near throw exception)
            virtual Player& drive(const City city);

            // fly to another city
            virtual Player& fly_direct(const City city);
            virtual Player& fly_charter(const City city);
            virtual Player& fly_shuttle(const City city);
            virtual Player& build();
            virtual Player& discover_cure(const City color);
            virtual Player& treat(const City city);
            virtual Player& take_card(const City city);
            virtual Player& remove_cards(const City city);
            string role() const;
    };
}
