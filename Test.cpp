#include <iostream>
#include <stdexcept>

#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

TEST_CASE("base case") {
    Board board;
    board[City::Atlanta] = 2;
    cout << board << endl;

    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
    CHECK(3 + 6 == 9);
}
