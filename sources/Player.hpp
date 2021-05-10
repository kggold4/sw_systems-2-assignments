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
            bool valid_city(const int city) const {
                if(city < 0 || city >= MAX_CITIES) { return false; }
                return true;
            }
        public:
            Player(Board& board, const int city);
            ~Player();

            // drive to given near city (if not near throw exception)
            virtual Player& drive(const int city);

            // fly to another city
            virtual Player& fly_direct(const int city);
            virtual Player& fly_charter(const int city);
            virtual Player& fly_shuttle(const int city);
            virtual Player& build();
            virtual Player& discover_cure(const int color);
            virtual Player& treat(const int city);
            virtual Player& take_card(const int city);
            virtual Player& remove_cards();
            string role() const;
    };
}
