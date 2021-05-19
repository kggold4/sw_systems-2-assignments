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

#include <string>

using namespace std;

namespace pandemic {
    enum Color {
        Blue,
        Yellow,
        Black,
        Red
    };

    static const unsigned int MAX_COLORS = 4;

    static Color color_by_index(const int i) { return static_cast<Color>(i); }

    static const string COLORS_NAMES[] = {"Blue", "Yellow", "Black", "Red"};

    static string get_color_name(const Color color) { return COLORS_NAMES[color_by_index(color)]; }

}
