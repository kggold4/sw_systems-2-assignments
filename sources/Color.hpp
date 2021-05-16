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

namespace pandemic {
    enum Color {
        Blue,
        Yellow,
        Black,
        Red
    };
    Color color_by_index(const int i) { return static_cast<Color>(i); }
}
