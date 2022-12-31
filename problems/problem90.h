//
// Created by Pratim on 12/31/22.
//

#ifndef PROJECT_EULER_PROBLEM90_H
#define PROJECT_EULER_PROBLEM90_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void generate_cubes(int i, int n, vector<int> & digits, unordered_set<int> & cube, vector<unordered_set<int>> & cubes) {
    if (n == 0) {
        cubes.push_back(cube);
        return;
    }
    if (i == digits.size()) return;
    for (int j = i; j < digits.size(); ++j) {
        cube.insert(digits[j]);
        generate_cubes(j + 1, n - 1, digits, cube, cubes);
        cube.erase(digits[j]);
    }
}

bool is_valid(unordered_set<int> cube1, unordered_set<int> cube2, vector<pair<int, int>> & squares) {
    for (auto square : squares) {
        if (cube1.count(9)) cube1.insert(6);
        if (cube2.count(9)) cube2.insert(6);
        if (cube1.count(6)) cube1.insert(9);
        if (cube2.count(6)) cube2.insert(9);
        if (cube1.count(square.first) && cube2.count(square.second)) continue;
        if (cube1.count(square.second) && cube2.count(square.first)) continue;
        return false;
    }
    return true;
}

void problem_90_solution(bool log) {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<pair<int, int>> squares = {{0, 1}, {0, 4}, {0, 9}, {1, 6}, {2, 5}, {3, 6}, {4, 9}, {6, 4}, {8, 1}};
    vector<unordered_set<int>> cubes;
    unordered_set<int> cube;
    generate_cubes(0, 6, digits, cube, cubes);

    int count = 0;
    for (int i = 0; i < cubes.size(); ++i) {
        for (int j = i+1; j < cubes.size(); ++j) {
            if (is_valid(cubes[i], cubes[j], squares)) count++;
        }
    }
    if (log) cout << count << endl;
}

#endif //PROJECT_EULER_PROBLEM90_H