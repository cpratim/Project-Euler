//
// Created by Allison Zhuang on 5/6/22.
//

#ifndef PROJECT_EULER_PROBLEM99_H
#define PROJECT_EULER_PROBLEM99_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int get_max_exp_index(string filename) {
    ifstream file(filename);
    string line;

    long max = 0;
    int index = 0;
    int max_index = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        int base = stoi(line.substr(0, line.find(',')));
        int exp = stoi(line.substr(line.find(',')+1, -1));
        long ln = exp * log(base);
        if (ln > max) {
            max = ln;
            max_index = index;
        }
        index += 1;
    }
    return max_index + 1;
}

void problem_99_solution(bool log) {
    string filename = "misc/p099_base_exp.txt";
    int max_index = get_max_exp_index(filename);
    if (log) cout << max_index << endl;
}

#endif //PROJECT_EULER_PROBLEM99_H
