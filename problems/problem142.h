//
// Created by Pratim Chowdhary on 12/09/22.
//

#ifndef PROJECT_EULER_PROBLEM142_H
#define PROJECT_EULER_PROBLEM142_H

#include "iostream"
#include "unordered_set"
#include "unordered_map"
#include "vector"

using namespace std;

void generate_map(vector<long> &squares, unordered_map<long, vector<long>> &map) {
    for (int i = 0; i < squares.size(); i++) {
        for (int j = i + 1; j < squares.size(); j++) {
            long sum = squares[i] + squares[j];
            if (sum % 2 != 0)
                continue;
            long x = sum / 2;
            if (map.find(x) == map.end())
                map.insert({x, vector<long>()});
            map.find(x)->second.push_back(x - squares[i]);
        }
    }
}


void problem_142_solution(bool log) {
    vector<long> squares;
    unordered_set<long> squares_set;
    unordered_map<long, vector<long>> map;
    int max = 1000;
    for (int i = 1; i <= max; i++) {
        long square = i * i;
        squares.push_back(square);
        squares_set.insert(square);
    }
    generate_map(squares, map);
    for (auto & itr : map) {
        if (itr.second.size() < 2)
            continue;
        long x = itr.first;
        for (int i = 0; i < itr.second.size(); i++) {
            for (int j = i + 1; j < itr.second.size(); j++) {
                long y = itr.second[i] > itr.second[j] ? itr.second[i] : itr.second[j];
                long z = itr.second[i] > itr.second[j] ? itr.second[j] : itr.second[i];
                if (squares_set.find(y + z) != squares_set.end() && squares_set.find(y - z) != squares_set.end()) {
                    if (log) cout << x + y + z << endl;
                    return;
                }
            }
        }
    }
}

#endif //PROJECT_EULER_PROBLEM142_H