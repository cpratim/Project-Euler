//
// Created by Pratim Chowdhary on 11/19/22.
//

#ifndef PROJECT_EULER_PROBLEM108_H
#define PROJECT_EULER_PROBLEM108_H

#include <iostream>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

struct node {
    long n;
    int s;
};

int generate_solutions(long n) {
    long x = n + 1;
    unordered_set<long> seen;
    int count = 0;
    while (!seen.contains(x)) {
        long top = n * x;
        long bottom = x - n;
        if (top % bottom == 0) {
            seen.insert((long) (top / bottom));
            count++;
        }
        x++;
    }
    return count;
}

long solve(int max, vector<int> &primes, int T) {
    queue<node> queue;
    unordered_set<long> visited;
    for (int prime: primes) {
        queue.push(node{prime, 1});
        visited.insert(prime);
    }
    while (!queue.empty()) {
        node top = queue.front();
        queue.pop();
        int solutions = generate_solutions(top.n);
        if (solutions > T) {
            return top.n;
        }
        if (top.n < max && solutions >= top.s) {
            for (int prime: primes) {
                if (visited.find(top.n * prime) == visited.end()) {
                    queue.push({top.n * prime, solutions});
                    visited.insert(top.n * prime);
                }
            }
        }
    }
    return -1;
}

void problem_108_solution(bool log) {
    vector<int> primes {2, 3, 5, 7, 11, 13};
    int max = 200000;
    int T = 1000;
    long total = solve(max, primes, T);
    if (log) cout << total << endl;
}

#endif //PROJECT_EULER_PROBLEM108_H
