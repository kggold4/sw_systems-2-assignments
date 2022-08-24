#include <string>
#include <stdexcept>
#include "snowman.hpp"

using namespace std;

// consts
const unsigned int MAX_NUMS = 8;
const unsigned int TEN = 10;
const std::string SPACE = " ";

// indexes for the string of the given id (to string)
enum index { i1, i2, i3, i4, i5, i6, i7, i8};

// implements of namespace ariel
namespace ariel {

    // hat 1
    std::string H1(char c) {
        switch(c) {
        case '1':
            return "_===_\n";
        case '2':
            return " ___\n";
        case '3':
            return "  _\n";
        case '4':
            return " ___\n";
        default:
            return "";
        }
    }

    // hat 2
    std::string H2(char c) {
        switch(c) {
        case '2':
            return ".....\n";
        case '3':
            return " /_\\\n";
        case '4':
            return "(_*_)\n";
        default:
            return "";
        }
    }

    // nose/mouth
    std::string N(char c) {
        switch(c) {
        case '1':
            return ",";
        case '2':
            return ".";
        case '3':
            return "_";
        default:
            return " ";
        }
    }

    // left/right eye
    std::string LR(char c) {
        switch(c) {
        case '1':
            return ".";
        case '2':
            return "o";
        case '3':
            return "O";
        case '4':
            return "-";
        default:
            return " ";
        }
    }

    // left arm
    std::string X(char c) {
        switch(c) {
        case '1':
            return "<";
        case '2':
            return "\\";
        case '3':
            return "/";
        default:
            return "";
        }
    }

    // right arm
    std::string Y(char c) {
        switch(c) {
        case '1':
            return ">";
        case '2':
            return "/";
        case '3':
            return "\\";
        default:
            return "";
        }
    }

    // torso
    std::string T(char c) {
        switch(c) {
        case '1':
            return " : ";
        case '2':
            return "] [";
        case '3':
            return "> <";
        default:
            return "   ";
        }
    }

    // base
    std::string B(char c) {
        switch(c) {
        case '1':
            return " : ";
        case '2':
            return "\" \"";
        case '3':
            return "___";
        default:
            return "   ";
        }
    }

    // snowman main function
    std::string snowman(unsigned int id) {

        // casting the id to a string and create result string
        std::string seq = std::to_string(id);
        std::string result;

        unsigned int temp = id;
        int i = 0;
        
        while (temp != 0) {
            // checking if the id contains only 1-4 digits
            if(temp % TEN < 1 || temp % TEN > 4) {
                throw std::invalid_argument("Invalid code '" + std::to_string(temp) + "'");
            }
            temp = temp / TEN;
            i++;
        }

        // checking if length of id is 8
        if(i != MAX_NUMS) {
            throw std::invalid_argument("Invalid code '" + std::to_string(temp) + "'");
        }

        // {H , N , L , R , X , Y , T , B }
        // {i1, i2, i3, i4, i5, i6, i7, i8}
        
        // hat
        // top of the hat
        if(seq[i5] != '4') { result.append(SPACE); }
        result.append(H1(seq[i1]));

        // bottom of the hat
        if(seq[i1] != '1') {
            if(seq[i5] != '4') { result.append(SPACE); }
            result.append(H2(seq[i1]));
        }

        // head
        if(seq[i5] == '2') { result.append(X(seq[i5])); }
        else if(seq[i5] != '4') { result.append(SPACE); }

        result.append("(" + LR(seq[i3]) + N(seq[i2]) + LR(seq[i4]) + ")");

        if(seq[i6] == '2') { result.append(Y(seq[i6])); }
        result.append("\n");

        // middle
        if(seq[i5] != '2') { result.append(X(seq[i5])); }
        else if(seq[i5] != '4') { result.append(SPACE); }

        result.append("(" + T(seq[i7]) + ")");

        if(seq[i6] != '2') { result.append(Y(seq[i6])); }
        
        result.append("\n");

        // bottom
        if(seq[i5] != '4') { result.append(SPACE); }
        result.append("(" + B(seq[i8]) + ")");

        return result;
    }
};
