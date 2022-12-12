//
// Created by Annie & Pratim on 12/12/22.
//

#ifndef PROJECT_EULER_PROBLEM83_H
#define PROJECT_EULER_PROBLEM83_H

#include "iostream"
#include "vector"
#include "fstream"
#include "sstream"
#include "queue"
#include "unordered_map"

#include "../include/string_lib.h"

using namespace std;

void read_matrix(string filename, int matrix[80][80]) {
    ifstream file(filename);
    string line;
    int i = 0;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        for (int j = 0; j < tokens.size(); j++) {
            matrix[i][j] = stoi(tokens[j]);
        }
        i++;
    }
}

long djikstra(int M, int N, int matrix[80][80]) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> queue;
    bool seen[80][80] = {false};
    int dist[80][80];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    dist[0][0] = matrix[0][0];
    queue.push(make_tuple(0, 0, 0));
    while (!queue.empty()) {
        tuple<int, int, int> top = queue.top();
        queue.pop();
        int d, i, j;
        tie(d, i, j) = top;
        if (seen[i][j]) continue;
        seen[i][j] = true;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (abs(di) == abs(dj)) continue;
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || ni >= M || nj < 0 || nj >= N || seen[ni][nj]) continue;
                int nd = min(dist[ni][nj], dist[i][j] + matrix[ni][nj]);
                dist[ni][nj] = nd;
                queue.push(make_tuple(nd, ni, nj));
            }
        }
    }
    return dist[M - 1][N - 1];
}

void problem_83_solution(bool log) {
    int M = 80, N = 80;
    int matrix[80][80];
    read_matrix("misc/p083_matrix.txt", matrix);
    long solution = djikstra(M, N, matrix);
    if (log) cout << solution << endl;
}


#endif //PROJECT_EULER_PROBLEM83_H