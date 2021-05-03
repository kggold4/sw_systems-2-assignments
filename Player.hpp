#pragma once

#include "Color.hpp"
#include "City.hpp"

namespace pandemic {
    class Player {
        private:
            pandemic::City current_city;
            unsigned int number_of_cards;
            char number_of_research_station;
        public:
            Player();
            void drive(City city);
            void fly_direct(City city);
            void fly_charter(City city);
            void fly_shuttle(City city);
            void bulid();
            void discover_curve();
            void treat();
            void role();
            void take_card();
    };
}