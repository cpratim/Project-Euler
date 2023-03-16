//
// Created by Pratim and Karun on 03/16/23.
//

#ifndef PROJECT_EULER_PROBLEM151_H
#define PROJECT_EULER_PROBLEM151_H

#include "iostream"
#include "vector"
#include "unordered_map"
#include "numeric"

using namespace std;

void cut(vector<int> & sheet, int d, int s) {
    sheet[s] -= d;
    for (int i = s+1; i < sheet.size(); i++) sheet[i] += d;
}

void backtrack(int i, int N, double p, int e, vector<int> & paper, unordered_map<int, double> & dist) {
    if (i == N) {
        dist[e] += p;
        return;
    }
    double t = (double) accumulate(paper.begin(), paper.end(), 0);
    for (int j = 0; j < paper.size(); j++) {
        if (paper[j] == 0) continue;
        int n = paper[j];
        cut(paper, 1, j);
        backtrack(i+1, N, p * (n / t), e + (int) (t == 1), paper, dist);
        cut(paper, -1, j);
    }
}

void problem_151_solution(bool log) {
    vector<int> paper {1, 0, 0, 0, 0};
    unordered_map<int, double> dist;
    backtrack(0, 15, 1.0, 0, paper, dist);
    double ans = 0;
    for (auto & [k, v] : dist) {
        ans += k * v;
    }
    if (log) cout << ans << endl;
}

#endif //PROJECT_EULER_PROBLEM151_H