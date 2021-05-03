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
            virtual Player
            void drive(const int city);
            void fly_direct(const int city);
            void fly_charter(const int city);
            void fly_shuttle(const int city);
            void bulid();
            void discover_curve();
            void treat(const int city);
            void role();
            void take_card(const int city);
    };
}
