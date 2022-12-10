//
// Created by Pratim on 12/09/22.
//

#ifndef PROJECT_EULER_PROBLEM105_H
#define PROJECT_EULER_PROBLEM105_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include "../include/string_lib.h"

using namespace std;

vector<vector<int>> read_sets(string filename) {
    ifstream file(filename);
    string line;
    vector<vector<int>> sets;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> str_set = split(line, ',');
        vector<int> set;
        for (const string& s : str_set) {
            set.push_back(stoi(s));
        }
        sets.push_back(set);
    }
    return sets;
}

void print_set(unordered_set<int> set) {
    for (int i : set) {
        cout << i << " ";
    }
    cout << endl;
}

bool check_set_sums(
        vector<int> set, int i, int n, int s, 
        unordered_set<int> &sums, unordered_map<int, tuple<int, int>> &range
    ) {
    if (i == set.size()) {
        if (sums.find(s) != sums.end()) 
            return false;
        sums.insert(s);
        if (range.find(n) == range.end())
            range[n] = make_tuple(s, s);
        range[n] = make_tuple(min(s, get<0>(range[n])), max(s, get<1>(range[n])));
        return true;
    }
    return check_set_sums(set, i + 1, n, s, sums, range) && check_set_sums(set, i + 1, n + 1, s + set[i], sums, range);
}

bool check_set(vector<int> set) {
    unordered_set<int> sums;
    unordered_map<int, tuple<int, int>> range;
    bool valid = check_set_sums(set, 0, 0, 0, sums, range);
    if (!valid)
        return false;
    for (int i = 1; i <= set.size(); i++) {
        if (get<0>(range[i]) <= get<1>(range[i-1]))
            return false;
    }
    return true;
}

void problem_105_solution(bool log) {
    vector<vector<int>> sets = read_sets("misc/p105_sets.txt");
    int sum = 0;
    for (vector<int> set : sets) {
        if (check_set(set))
            sum += accumulate(set.begin(), set.end(), 0);
    }
    if (log) cout << sum << endl;   

}


#endif //PROJECT_EULER_PROBLEM105_H