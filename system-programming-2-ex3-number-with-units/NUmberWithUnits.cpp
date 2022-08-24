/**
 * 
 * Assignment #3
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

// includes
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "NumberWithUnits.hpp"

// namespaces
using namespace std;
using namespace ariel;

// implement ariel namespace
namespace ariel {

    static map<string, map<string, double>> T;
    const double EPS = 0.00001;
    const int ZERO = 0;
    const int ONE = 1;

    // implement constructor
    NumberWithUnits::NumberWithUnits(double value, const string& type) {
        bool valid = false;
        for(auto &v : T) {
            if(valid) { break; }
            for(auto &w : v.second) {
                if(type == w.first) { valid = true; break; }
            }
        }
        if(valid) {
            this->unit_value = value;
            this->unit_type = type;
        } else { throw std::invalid_argument("Not a valid type of unit!"); }
        
    }

    // implement read_units function
    void NumberWithUnits::read_units(ifstream& units_file) {

        double amount_1 = ZERO;
        double amount_2 = ZERO;
        string unit_1;
        string unit_2;
        string mark;

        while(units_file >> amount_1 >> unit_1 >> mark >> amount_2 >> unit_2) {
            T[unit_1][unit_2] = amount_2;
            T[unit_2][unit_1] = ONE / amount_2;
            for(const auto& kv: T[unit_2]) {
                const auto& key = kv.first;
                const auto& value = kv.second;
                double ans = T[unit_1][unit_2] * value;
                T[unit_1][key] = ans;
                T[key][unit_1] = ONE / ans;
            }
            for(const auto& kv: T[unit_1]) {
                const auto& key = kv.first;
                const auto& value = kv.second;
                double ans = T[unit_2][unit_1] * value;
                T[unit_2][key] = ans;
                T[key][unit_2] = ONE / ans;
            }
        }
    }

    // casting unit number to another unit number function
    static double casting_units(const string& from_unit, const string& to_unit, double value) {
        double ans = ZERO;
        if(from_unit == to_unit) { ans = value; }
        else if(from_unit.empty() || to_unit.empty()) { throw invalid_argument{"Units cannot be empty"}; }
        else {
            try { ans = value * T.at(from_unit).at(to_unit); }
            catch(const exception& e) {
                throw invalid_argument{"Units do not match - [" + from_unit + "] cannot be converted to [" + to_unit + "]"};
            }
        }
        return ans;
    }

    // compare between unit numbers function
    static int compare_units(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        int ans = ZERO;
        if(unit_number_1.getValue() - casting_units(unit_number_2.getType(), unit_number_1.getType(), unit_number_2.getValue()) > EPS) { ans = ONE; }
        else if(casting_units(unit_number_2.getType(), unit_number_1.getType(), unit_number_2.getValue()) - unit_number_1.getValue() > EPS) { ans = -1; }
        return ans;
    }

    // implement getValue method
    double NumberWithUnits::getValue() const { return this->unit_value; }

    // implement getType methods
    string NumberWithUnits::getType() const { return this->unit_type; }


    /** overloading in and out operators */

    // >> operator
    istream& operator>>(istream& ist, NumberWithUnits& unit_number) {

        double value = 0;
        string type;
        char ch = ']';
        ist >> value >> ch;
        while(ch != ']') {
            if(ch != '[') { type.insert(type.end(), ch); }
            ist >> ch;
        }
        if(T.empty()) { throw std::invalid_argument("types cannot match " + type + " != " + type); }
        T.at(type);
        if(T[type][type] == 0 && type != type) {
            throw std::invalid_argument("types cannot match " + type + " != " + type);
        }
        unit_number.unit_value = value;
        unit_number.unit_type = type;
        return ist;
    }

    // << operator
    ostream& operator<<(ostream& ost, const NumberWithUnits& unit_number) {
        ost << unit_number.unit_value << '[' << unit_number.unit_type << ']';
        return ost;
    }

    /** overloading arithmetic operators */

    // + operators
    NumberWithUnits operator+(const NumberWithUnits& unit_number) {
        return NumberWithUnits{(unit_number.unit_value), unit_number.unit_type};
    }

    NumberWithUnits operator+(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting_units(unit_number_2.unit_type, unit_number_1.unit_type, unit_number_2.unit_value);
        return NumberWithUnits(unit_number_1.unit_value + temp, unit_number_1.unit_type);
    }

    NumberWithUnits operator+(const NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.unit_value + number, unit_number.unit_type);
    }

    // ++ operators
    NumberWithUnits &NumberWithUnits::operator++() {
        this->unit_value = this->unit_value + ONE;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int) {
        return NumberWithUnits{this->unit_value++, this->unit_type};
    }

    // += operator
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& unit_number) {
        if(this->unit_type == unit_number.unit_type) {
            this->unit_value = this->unit_value + unit_number.unit_value;
            return *this;
        }
        try {
            double v = T.at(unit_number.unit_type).at(this->unit_type);
            this->unit_value = this->unit_value + (v * unit_number.unit_value);
            return *this;
        } catch(const exception &e) {
            throw std::invalid_argument("Units do not match - [" + unit_number.unit_type + "] cannot be converted to [" + this->unit_type + "]");
        }
    }

    // - operators
    NumberWithUnits operator-(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting_units(unit_number_2.unit_type, unit_number_1.unit_type, unit_number_2.unit_value);
        return NumberWithUnits(unit_number_1.unit_value-temp, unit_number_1.unit_type);
    }
    NumberWithUnits operator-(const NumberWithUnits& unit_number) {
        return NumberWithUnits(-unit_number.unit_value, unit_number.unit_type);
    }

    // -- operators
    NumberWithUnits &NumberWithUnits::operator--() {
        this->unit_value = this->unit_value - ONE;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator--(int) {
        return NumberWithUnits{this->unit_value--, this->unit_type};
    }

    // -= operator
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& unit_number) {
        if(this->unit_type == unit_number.unit_type) {
            this->unit_value = this->unit_value - unit_number.unit_value;
            return *this;
        }
        try {
            double v = T.at(unit_number.unit_type).at(this->unit_type);
            this->unit_value = this->unit_value - (v * unit_number.unit_value);
            return *this;
        } catch(const exception &e) {
            throw std::invalid_argument("Units do not match - [" + unit_number.unit_type + "] cannot be converted to [" + this->unit_type + "]");
        }
    }

    // * operators
    NumberWithUnits operator*(const NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.unit_value *number, unit_number.unit_type);
    }
    NumberWithUnits operator*(double number, const NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.unit_value * number, unit_number.unit_type);
    }

    // *= operators
    NumberWithUnits operator*=(NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.unit_value = unit_number.unit_value * number, unit_number.unit_type);
    }
    NumberWithUnits operator*=(double number, NumberWithUnits& unit_number) {
        return NumberWithUnits(number * unit_number.unit_value, unit_number.unit_type);
    }

    /** equality operators */

    // == operator
    bool operator==(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) == ZERO;
    }

    // != operator
    bool operator!=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) != ZERO;
    }

    // < and <= operators
    bool operator<(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) < ZERO;
    }
    bool operator<=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) <= ZERO;
    }

    // > and >= operators
    bool operator>(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) > ZERO;
    }
    bool operator>=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) >= ZERO;
    }
}
