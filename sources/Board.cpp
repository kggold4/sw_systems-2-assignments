/**
 * 
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */
#include <set>
#include <map>
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

namespace pandemic {

    // number of cities
    static const unsigned int MAX_CITIES = 48;

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

    static bool has_station[MAX_CITIES] = { false };

    // board constructor
    Board::Board() {
        for(int i = 0; i < MAX_CITIES; i++) {
            cities_cubes[i] = 0;
            string name_city = CITIES_NAMES[i];
            cities_names[i] = name_city;
        }
    }

    Board::~Board() {}

    bool Board::is_clean() const {
        bool ans = true;
        for(int i = 0; i < MAX_CITIES; i++) {
            if(get_city_cubes(i) > 0) {
                ans = false;
                break;
            }
        }
        return ans;
    }

    void Board::remove_cures() {

    }
    
    void Board::remove_stations() {

    }

    int& Board::operator[](int city) {
        return cities_cubes[city];
    }

    ostream& operator<<(ostream& ost, const Board& board) {

        for(int i = 0; i < MAX_CITIES; i++) {
            ost << i << " [" << board.get_city_name(i) << "]: " << board.get_city_cubes(i) << endl;
        }

        return ost;
    }
}
