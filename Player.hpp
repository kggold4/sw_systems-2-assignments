#pragma once

#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic {
    class Player {
        private:
            City current_city;
            Board board;
            unsigned int number_of_cards;
            char number_of_research_station;
        public:
            Player(Board& board, const int city);
            ~Player();
            virtual Player& drive(const int city);
            virtual Player& fly_direct(const int city);
            virtual Player& fly_charter(const int city);
            virtual Player& fly_shuttle(const int city);
            virtual Player& bulid();
            virtual Player& discover_cure(const int color);
            virtual Player& treat(const int city);
            virtual Player& take_card(const int city);
            virtual Player& remove_cards();
            string role();
    };
}
