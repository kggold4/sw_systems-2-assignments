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

#include <iostream>
#include <string>
#include <map>
#include "Color.hpp"

using namespace std;

namespace pandemic {
    class Board {
        private:
            // pandemic::Color color;
            map<int, int> cities_cubes;
            map<int, string> cities_names;
        public:

            // constructor
            Board();

            // de-constructor
            ~Board();

            bool is_clean() const;
            void remove_cures();
            void remove_stations();

            // get reference of city in cities_cubes map
            int& operator[](int city);

            // output ostream
            friend ostream& operator<<(ostream& ost, const Board& board);

            // return a name of a city (0 <= i < 48)
            string get_city_name(const City city) const { return this->cities_names.at(city); }

            // return a number of cubes in a city (0 <= i < 48)
            int get_city_cubes(const City city) const { return this->cities_cubes.at(city); }

            void increase_city_cubes(const City city) { this->cities_cubes.at(city)++; }
            void decrease_city_cubes(const City city) { this->cities_cubes.at(city)--; }
    };
}
