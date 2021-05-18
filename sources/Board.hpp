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
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic {
    class Board {
        private:
            // disease cube in each city
            map<City, int> cities_cubes;

            // each city has name
            map<int, string> cities_names;

            // each city can have a research station
            map<City, bool> research_stations;

            // cures discovered
            map<Color, bool> cures;
        public:

            // constructor
            Board();

            // de-constructor
            ~Board();

            /**
             * board methods
             */

            // return true if all the cities that on the board are clean from disease
            bool is_clean();

            // remove all cures from all the cities that on the board
            void remove_cures();

            // remove all the research stations from all the cities that on the board
            void remove_stations();

            // get reference of city in cities_cubes map
            int& operator[](City city);

            // output ostream
            friend ostream& operator<<(ostream& ost, const Board& board);

            /**
             * cities methods
             */

            // return a number of cubes in a city (0 <= i < 48)
            int get_city_cubes(const City city) const { return this->cities_cubes.at(city); }

            // return true of if the given city has a research station
            bool has_research_station(const City city) { return this->research_stations.find(city)->second; }

            // set city as have a research station
            void set_research_station(const City city) { this->research_stations.find(city)->second = true; }

            /**
             * colors methods
             */
            // return true if color has curve
            bool has_cure(const Color color) { return this->cures.find(color)->second; }

            // set cure of color
            void set_cure(const Color color) { this->cures.find(color)->second = true; }

            // delete cure of color
            void del_cure(const Color color) { this->cures.find(color)->second = false; }
    };
}
