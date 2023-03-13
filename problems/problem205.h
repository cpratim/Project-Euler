//
// Created by Pratim Chowdhary on 02/10/23.
//

#ifndef PROJECT_EULER_PROBLEM205_H
#define PROJECT_EULER_PROBLEM205_H

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename T, typename U> using umap = unordered_map<T, U>;

long multi_coef(int n, vector<int> & k) {
    long num = factorial(n);
    long den = 1;
    for (int i = 0; i < k.size(); i++) {
        den *= factorial(k[i]);
    }
    return num / den;
}

void generate_distribution(int i, int n, int s, int l, umap<int, int> & roll, umap<int, double> & dist) {
    if (i == n) {
        vector<int> k;
        long t = 0;
        for (auto [v, f]: roll) {
            if (f == 0) continue;
            k.push_back(f);
            t += f * v;
        }
        dist[t] += (multi_coef(n, k) * (1.0 / pow(s, n)));
        return;
    }
    for (int j = l; j <= s; j++) {
        roll[j]++;
        generate_distribution(i + 1, n, s, l, roll, dist);
        roll[j]--;
    }
}

void problem_205_solution(bool log) {
    umap<int, double> peter, colin;
    umap<int, int> roll;
    generate_distribution(0, 9, 4, 1, roll, peter);
    generate_distribution(0, 6, 6, 1, roll, colin);
    double p = 0;
    for (const auto [v, f]: peter) {
        for (const auto [v2, f2]: colin) {
            if (v > v2) p += f * f2;
        }
    }
    if (log) cout << p << endl;
}


#endif //PROJECT_EULER_PROBLEM205_H
