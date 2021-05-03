#pragma once
#include "Color.hpp"

namespace pandemic {
    class Board {
        private:
            pandemic::Color color;
        public:
            boolean is_clean();
            void remove_cures();

    };
}


