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
    static Color color_by_index_enum(const int i) { return static_cast<Color>(i); }
}
