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
#include <map>
#include <string>

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

            // deconstructor
            ~Board();

            bool is_clean();
            void remove_cures();
            void remove_stations();

            // get reference of city in cities_cubes map
            int& operator[](int city);

            // output ostream
            friend ostream& operator<<(ostream& ost, const Board& board);

            // return a name of a city (0 <= i < 48)
            string get_city_name(const int i) const { return this->cities_names.at(i); }

            // return a number of cubes in a city (0 <= i < 48)
            int get_city_cubes(const int i) const { return this->cities_cubes.at(i); }
    };
}
