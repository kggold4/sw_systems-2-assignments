#pragma once
#include "Color.hpp"

namespace pandemic {
    class Board {
        private:
            pandemic::Color color;
        public:
            Board();
            boolean is_clean();
            void remove_cures();

    };
}
