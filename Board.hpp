#pragma once

#include <iostream>
#include <map>

#include "Color.hpp"

using namespace std;

namespace pandemic {
    class Board {
        private:
            //pandemic::Color color;
            map<int,int> T;
        public:

            // constructor
            Board();

            // deconstructor
            ~Board();

            bool is_clean();
            void remove_cures();
            void remove_stations();

            // get reference of city in T map
            int& operator[](int city);
            friend ostream& operator<<(ostream& ost, const Board& board);
    };
}
