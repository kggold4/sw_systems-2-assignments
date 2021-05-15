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
            map<int, int> cities_cubes;

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

            bool is_clean() const;
            void remove_cures();
            void remove_stations();

            // get reference of city in cities_cubes map
            int& operator[](int city);

            // output ostream
            friend ostream& operator<<(ostream& ost, const Board& board);

            // cities methods on boards:

            // return a name of a city (0 <= i < 48)
            string get_city_name(const City city) const { return this->cities_names.at(city); }

            // return a number of cubes in a city (0 <= i < 48)
            int get_city_cubes(const City city) const { return this->cities_cubes.at(city); }

            void increase_city_cubes(const City city) { this->cities_cubes.at(city)++; }
            void decrease_city_cubes(const City city) { this->cities_cubes.at(city)--; }

            // return true of if the given city has a research station
            bool has_research_station(const City city) { return this->research_stations.find(city)->second; }

            // return true if color has curve
            bool has_cure(const Color color) { return this->cures.find(color)->second; }
            void set_cure(const Color color) { this->cures.find(color) = true; }
            void del_cure(const Color color) { this->cures.find(color) = false; }
    };
}
