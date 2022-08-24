#include <iostream>
#include <stdexcept>
#include <random>

#include "doctest.h"
#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/Player.hpp"
#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/Virologist.hpp"

using namespace std;
using namespace pandemic;

static const int MAX_CITIES = 47;
static const int MIN_CITIES = 0;
static const int MAX_CUBES = 5;
static const int MIN_CUBES = 1;
static const int NUMBER_OF_CHECKS_LOOP = 500;

static int get_random_city() {
    return MIN_CITIES + (rand() % (MAX_CITIES - MIN_CITIES + 1));
}

static int get_random_cube() {
    return MIN_CUBES + (rand() % (MAX_CUBES - MIN_CUBES + 1));
}

TEST_CASE("board is_clean method check") {
    Board board;

    int i = 0;
    while(i < NUMBER_OF_CHECKS_LOOP) {
        int random_city = get_random_city();
        CHECK(board.is_clean() == true);
        int random_cube = get_random_cube();
        board[random_city] = random_cube;
        CHECK(board.is_clean() == false);
        board[random_city] = 0;
        CHECK(board.is_clean() == true);
        ++i;
    }
}
