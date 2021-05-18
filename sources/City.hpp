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
    static City city_by_index_enum(const int i) { return static_cast<City>(i); }
    static const string CITIES_NAMES[] = {"Algiers", "Atlanta", "Baghdad", "Bangkok", "Beijing", "Bogota", "BuenosAires", "Cairo", "Chennai", "Chicago", "Delhi", "Essen", "HoChiMinhCity", "HongKong", "Istanbul", "Jakarta", "Johannesburg", "Karachi", "Khartoum", "Kinshasa", "Kolkata", "Lagos", "Lima", "London", "LosAngeles", "Madrid", "Manila", "MexicoCity", "Miami", "Milan", "Montreal", "Moscow", "Mumbai", "NewYork", "Osaka", "Paris", "Riyadh", "SanFrancisco", "Santiago", "SaoPaulo", "Seoul", "Shanghai", "StPetersburg", "Sydney", "Taipei", "Tehran", "Tokyo", "Washington"};
    static const Color CITIES_COLORS[] = {Black, Blue, Black, Red, Red, Yellow, Yellow, Black, Black, Blue, Black, Blue, Red, Red, Black, Red, Yellow, Black, Yellow, Yellow, Black, Yellow, Yellow, Blue, Yellow, Blue, Red, Yellow, Yellow, Blue, Blue, Black, Black, Blue, Red, Blue, Black, Blue, Yellow, Yellow, Red, Red, Blue, Red, Red, Black, Red, Blue};
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
}