//
// Created by Pratim on 12/02/22.
//

#ifndef PROJECT_EULER_PROBLEM89_H
#define PROJECT_EULER_PROBLEM89_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<tuple<string, int>> table = {
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"XL", 40},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1}
};

int get_value(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

vector<string> read_file(string filename) {
    vector<string> lines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        lines.push_back(line);
    }
    return lines;
}

int int_to_roman(int n) {
    string roman;
    for (auto [r, v]: table) {
        while (n >= v) {
            roman += r;
            n -= v;
        }
    }
    return roman.length();
}

int roman_to_int(string roman) {
    int n = 0;
    for (int i = 0; i < roman.length(); i++) {
        int s1 = get_value(roman[i]);
        if (i + 1 < roman.length()) {
            int s2 = get_value(roman[i + 1]);
            if (s1 >= s2) {
                n += s1;
            } else {
                n += s2 - s1;
                i++;
            }
        } else {
            n += s1;
            i++;
        }
    }
    return n;
}

void problem_89_solution(bool log) {
    int saved = 0;
    vector<string> lines = read_file("misc/p089_roman.txt");
    for (auto &line: lines) {
        int n = roman_to_int(line);
        int roman = int_to_roman(n);
        saved += line.length() - roman;
    }
    if (log) cout << saved << endl;
}

#endif //PROJECT_EULER_PROBLEM89_H
