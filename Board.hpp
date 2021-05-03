#pragma once
#include <iostream>
#include "Color.hpp"

using namespace std;

namespace pandemic {
    class Board {
        private:
            pandemic::Color color;
        public:
            Board();
            bool is_clean();
            void remove_cures();
            int& operator[](int city);
            friend Board operator<<(ostream& ost, const Board& board);
    };
}
