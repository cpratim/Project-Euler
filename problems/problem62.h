//
// Created by Allison, Karun, Pratim on 5/8/22.
//

#ifndef PROJECT_EULER_PROBLEM62_H
#define PROJECT_EULER_PROBLEM62_H

#include "iostream"
#include "unordered_map"
#include "string"
#include "cmath"
// #include <algorithm>

using namespace std;

string hash_permutation(long n) {
    string str = to_string(n);
    sort(str.begin(), str.end());
    return str;
}

void problem_62_solution(bool log) {
    unordered_map<string, int> map {{"0", 0}};
    unordered_map<string, long> cubes;
    int min_perm = 5;
    string key = "0";
    int n = 1;
    while (map[key] != min_perm) {
        long cube = (long) pow(n, 3);

        key = hash_permutation(cube);
        if (map.find(key) == map.end()) {
            map.insert({key, 0});
            cubes.insert({key, cube});
        }
        map[key] += 1;
        n++;
    }
    if (log) cout << cubes.find(key)->second << endl;
}

#endif //PROJECT_EULER_PROBLEM62_H
