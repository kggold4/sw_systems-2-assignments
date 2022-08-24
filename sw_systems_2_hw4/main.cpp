/**
 *
 * Assignment #4
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 *
 * */

#include <iostream>
#include <string>

#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"
#include "sources/Player.hpp"

#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/Medic.hpp"
#include "sources/Virologist.hpp"

using namespace std;

Color get_color() {
    while(true) {
        cout << "Please enter the color:" << endl;
        cout << "Options:\n(0)Exit-Game (1)Blue (2)Yellow (3)Black (4)Red" << endl << endl;
        int color_id;
        cin >> color_id;
        if(color_id == 0) { exit(1); }
        if(color_id < 0 || color_id > 4) {
            cout << "Invalid color - please try again" << endl << endl;
        } else {
            return color_by_index(color_id-1);
        }
    }
}

City get_city() {
    while(true) {
        cout << "Please enter the city:" << endl;
        cout << "Options:\n(0)Exit-Game (1)Algiers (2)Atlanta (3)Baghdad (4)Bangkok (5)Beijing (6)Bogota (7)BuenosAires (8)Cairo (9)Chennai (10)Chicago (11)Delhi (12)Essen,\n(13)HoChiMinhCity (14)HongKong (15)Istanbul (16)Jakarta (17)Johannesburg (18)Karachi (19)Khartoum (20)Kinshasa (21)Kolkata (22)Lagos (23)Lima (24)London,\n(25)LosAngeles (26)Madrid (27)Manila (28)MexicoCity (29)Miami (30)Milan (31)Montreal (32)Moscow (33)Mumbai (34)NewYork (35)Osaka (36)Paris,\n(37)Riyadh (38)SanFrancisco (39)Santiago (40)SaoPaulo (41)Seoul (42)Shanghai (43)StPetersburg (44)Sydney (45)Taipei (46)Tehran (47)Tokyo (48)Washington" << endl << endl;
        int city_id;
        cin >> city_id;
        if(city_id == 0) { exit(1); }
        if(city_id < 0 || city_id > 48) {
            cout << "Invalid city - please try again" << endl << endl;
        } else {
            return city_by_index(city_id-1);
        }
    }
}

int get_player_role() {
    // player role
    while(true) {
        cout << "Please enter the role type for player:" << endl;
        cout << "Options:\n(0)Exit-Game (1)Player (2)Dispatcher (3)FieldDoctor (4)GeneSplicer (5)Medic (6)OperationsExpert (7)Researcher (8)Scientist (9)Virologist" << endl << endl;
        int role_id;
        cin >> role_id;
        if(role_id == 0) { exit(1); }
        if(role_id < 0 || role_id > 9) {
            cout << "Invalid role - please try again" << endl << endl;
        } else {
            return role_id;
        }
    }
}

int get_n() {
    while(true) {
        cout << "Please enter the n limit cards of scientist: (n >= 0)" << endl;
        int n;
        cin >> n;
        if(n < 0) {
            cout << "Invalid n number - please try again" << endl;
        } else {
            return n;
        }
    }
}

int main() {

    Board board;
    cout << "Choose city to start:" << endl;
    City start_city = get_city();
    int role_id = get_player_role(), n;

    Player player(board, start_city);

    switch (role_id) {
        case 2:
            player = Dispatcher{board, start_city};
            break;
        case 3:
            player = FieldDoctor{board, start_city};
            break;
        case 4:
            player = GeneSplicer{board, start_city};
            break;
        case 5:
            player = Medic{board, start_city};
            break;
        case 6:
            player = OperationsExpert{board, start_city};
            break;
        case 7:
            player = Researcher{board, start_city};
            break;
        case 8:
            n = get_n();
            player = Scientist{board, start_city, n};
            break;
        case 9:
            player = Virologist{board, start_city};
            break;
    }

    while(true) {
        cout << "Choose operation to play the game:" << endl;
        cout << "Options:\n(0)Exit-Game\n\nPlayer Operations:\n(1)drive (2)fly_direct (3)fly_charter (4)fly_shuttle (5)build (6)discover_cure (7)treat (8)take_card (9)remove_cards (10)role" << endl << endl;
        cout << "Board Operations:\n(11)Print-Board (12)is_clean (13)remove_cures (14)remove_stations" << endl << endl;
        cout << "Special Operations:\n(15)current-city (16)connections-to-city" << endl << endl;
        int operation;
        cin >> operation;
        City city = start_city;
        Color color;
        if(operation == 0) { exit(1); }
        if(operation < 0 || operation > 16) {
            cout << "Invalid operation - please try again" << endl << endl;
        } else {
            switch (operation) {
                case 1:
                    cout << "Choose city to drive:" << endl;
                    city = get_city();
                    player.drive(city);
                    cout << "Player drive to " << get_city_name(city) << endl << endl;
                    break;
                case 2:
                    cout << "Choose city to fly:" << endl;
                    city = get_city();
                    player.fly_direct(city);
                    cout << "Player fly to " << get_city_name(city) << endl << endl;
                    break;
                case 3:
                    cout << "Choose city to fly:" << endl;
                    city = get_city();
                    player.fly_charter(city);
                    cout << "Player fly to " << get_city_name(city) << endl << endl;
                    break;
                case 4:
                    cout << "Choose city to fly:" << endl;
                    city = get_city();
                    player.fly_shuttle(city);
                    cout << "Player fly to " << get_city_name(city) << endl << endl;
                    break;
                case 5:
                    player.build();
                    cout << "Player build" << endl << endl;
                    break;
                case 6:
                    cout << "Choose color:" << endl;
                    color = get_color();
                    player.discover_cure(color);
                    cout << "Player discover cure" << endl << endl;
                    break;
                case 7:
                    cout << "Choose city to treat:" << endl;
                    city = get_city();
                    player.treat(city);
                    cout << "Player treat " << get_city_name(city) << endl << endl;
                    break;
                case 8:
                    cout << "Choose city to take card:" << endl;
                    city = get_city();
                    player.take_card(city);
                    cout << "Player taken card " << get_city_name(city) << endl << endl;
                    break;
                case 9:
                    player.remove_cards();
                    cout << "Player removed cards" << endl << endl;
                    break;
                case 10:
                    cout << "Player role is: " << player.role() << endl << endl;
                    break;
                case 11:
                    cout << board << endl << endl;
                    break;
                case 12:
                    cout << "Board is clean: " << board.is_clean() << endl << endl;
                    break;
                case 13:
                    board.remove_cures();
                    cout << "Board removed cures" << endl << endl;
                    break;
                case 14:
                    board.remove_stations();
                    cout << "Board removed research stations" << endl;
                    break;
                case 15:
                    cout << "Current city: " << get_city_name(city_by_index(city)) << endl << endl;
                    break;
                case 16:
                    set<City> connection = city_map.at(city);
                    cout << "Connections: [";
                    for(const auto& c : connection) {
                        cout << get_city_name(city_by_index(c)) << ' ';
                    }
                    cout << ']' << endl << endl;
                    break;
            }
        }
    }

    exit(1);
}