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

#include <set>
#include <map>
#include "Color.hpp"

using namespace std;

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

    static const Map<City, Color> CITIES_MAP {
            { Algiers, Black },
            { Atlanta, Blue },
            { Baghdad, Black },
            { Bangkok, Red },
            { Beijing, Red },
            { Bogota, Yellow },
            { BuenosAires, Yellow },
            { Cairo, Black },
            { Chennai, Black },
            { Chicago, Blue },
            { Delhi, Black },
            { Essen, Blue },
            { HoChiMinhCity, Red },
            { HongKong, Red },
            { Istanbul, Black },
            { Jakarta, Red },
            { Johannesburg, Yellow },
            { Karachi, Black },
            { Khartoum, Yellow },
            { Kinshasa, Yellow },
            { Kolkata, Black },
            { Lagos, Yellow },
            { Lima, Yellow },
            { London, Blue },
            { LosAngeles, Yellow },
            { Madrid, Blue },
            { Manila, Red },
            { MexicoCity, Yellow },
            { Miami, Yellow },
            { Milan, Blue },
            { Montreal, Blue },
            { Moscow, Black },
            { Mumbai, Black },
            { NewYork, Blue },
            { Osaka, Red },
            { Paris, Blue },
            { Riyadh, Black },
            { SanFrancisco, Blue },
            { Santiago, Yellow },
            { SaoPaulo, Yellow },
            { Seoul, Red },
            { Shanghai, Red },
            { StPetersburg, Blue },
            { Sydney, Red },
            { Taipei, Red },
            { Tehran, Black },
            { Tokyo, Red },
            { Washington, Blue }
    };

    // connections between cities
    static const map<City, set<City>> city_map {
            {Algiers,{Madrid, Paris, Istanbul, Cairo}},
            {Atlanta,{Chicago, Miami, Washington}},
            {Baghdad,{Tehran, Istanbul, Cairo, Riyadh, Karachi}},
            {Bangkok,{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
            {Beijing,{Shanghai, Seoul}},
            {Bogota,{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
            {BuenosAires,{Bogota, SaoPaulo}},
            {Cairo,{Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
            {Chennai,{Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
            {Chicago,{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
            {Delhi,{Tehran, Karachi, Mumbai, Chennai, Kolkata}},
            {Essen,{London, Paris, Milan, StPetersburg}},
            {HoChiMinhCity,{Jakarta, Bangkok, HongKong, Manila}},
            {HongKong,{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
            {Istanbul,{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
            {Jakarta,{Chennai, Bangkok, HoChiMinhCity, Sydney}},
            {Johannesburg,{Kinshasa, Khartoum}},
            {Karachi,{Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
            {Khartoum,{Cairo, Lagos, Kinshasa, Johannesburg}},
            {Kinshasa,{Lagos, Khartoum, Johannesburg}},
            {Kolkata,{Delhi, Chennai, Bangkok, HongKong}},
            {Lagos,{SaoPaulo, Khartoum, Kinshasa}},
            {Lima,{MexicoCity, Bogota, Santiago}},
            {London,{NewYork, Madrid, Essen, Paris}},
            {LosAngeles,{SanFrancisco, Chicago, MexicoCity, Sydney}},
            {Madrid,{London, NewYork, Paris, SaoPaulo, Algiers}},
            {Manila,{Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
            {MexicoCity,{LosAngeles, Chicago, Miami, Lima, Bogota}},
            {Miami,{Atlanta, MexicoCity, Washington, Bogota}},
            {Milan,{Essen, Paris, Istanbul}},
            {Montreal,{Chicago, Washington, NewYork}},
            {Moscow,{StPetersburg, Istanbul, Tehran}},
            {Mumbai,{Karachi, Delhi, Chennai}},
            {NewYork,{Montreal, Washington, London, Madrid}},
            {Osaka,{Taipei, Tokyo}},
            {Paris,{Algiers, Essen, Madrid, Milan, London}},
            {Riyadh,{Baghdad, Cairo, Karachi}},
            {SanFrancisco,{LosAngeles, Chicago, Tokyo, Manila}},
            {Santiago,{Lima}},
            {SaoPaulo,{Bogota, BuenosAires, Lagos, Madrid}},
            {Seoul,{Beijing, Shanghai, Tokyo}},
            {Shanghai,{Beijing, HongKong, Taipei, Seoul, Tokyo}},
            {StPetersburg,{Essen, Istanbul, Moscow}},
            {Sydney,{Jakarta, Manila, LosAngeles}},
            {Taipei,{Shanghai, HongKong, Osaka, Manila}},
            {Tehran,{Baghdad, Moscow, Karachi, Delhi}},
            {Tokyo,{Seoul, Shanghai, Osaka, SanFrancisco}},
            {Washington,{Atlanta, NewYork, Montreal, Miami}}
    };

    // get city and return it's index
    static City city_by_index(const int i) { return static_cast<City>(i); }

    // return a name of a city (0 <= i < 48)
    static string get_city_name(const City city) const { return CITIES_NAMES[city_by_index(city)]; }

    // return the city color
    static Color get_city_color(const City city) { return CITIES_MAP.at(city); }
}
