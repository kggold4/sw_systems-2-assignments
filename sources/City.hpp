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

#include "Color.hpp"

namespace pandemic {
    enum City {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };
    static const string CITIES_NAMES[] = {"Algiers", "Atlanta", "Baghdad", "Bangkok", "Beijing", "Bogota", "BuenosAires", "Cairo", "Chennai", "Chicago", "Delhi", "Essen", "HoChiMinhCity", "HongKong", "Istanbul", "Jakarta", "Johannesburg", "Karachi", "Khartoum", "Kinshasa", "Kolkata", "Lagos", "Lima", "London", "LosAngeles", "Madrid", "Manila", "MexicoCity", "Miami", "Milan", "Montreal", "Moscow", "Mumbai", "NewYork", "Osaka", "Paris", "Riyadh", "SanFrancisco", "Santiago", "SaoPaulo", "Seoul", "Shanghai", "StPetersburg", "Sydney", "Taipei", "Tehran", "Tokyo", "Washington"};
    static const Color CITIES_COLORS[] = {Black, Blue, Black, Red, Red, Yellow, Yellow, Black, Black, Blue, Black, Blue, Red, Red, Black, Red, Yellow, Black, Yellow, Yellow, Black, Yellow, Yellow, Blue, Yellow, Blue, Red, Yellow, Yellow, Blue, Blue, Black, Black, Blue, Red, Blue, Black, Blue, Yellow, Yellow, Red, Red, Blue, Red, Red, Black, Red, Blue};
}