//
// Created by Pratim Chowdhary on 12/22/23.
//

#ifndef PROJECT_EULER_PROBLEM240_H
#define PROJECT_EULER_PROBLEM240_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long count_permutation(vector<int> & dice, vector<long long> & factorial) {
    int N = dice.size();
    long long result = factorial[N];
    unordered_map<int, int> count;
    for (int i = 0; i < N; i++) 
        count[dice[i]]++;
    for (auto & p : count)
        result /= factorial[p.second];
    return result;
}

long long solve(int i, int n_dice, int n_top, int sum, int max_dice, vector<int> & dice, vector<long long> & factorial) {
    if (i == n_top and sum != 0)
        return 0;
    if (n_dice == 0)
        return count_permutation(dice, factorial);

    long long result = 0;
    for (int j = 1; j <= max_dice; ++j) {
        dice.push_back(j);
        result += solve(i + 1, n_dice - 1, n_top, sum - j, j, dice, factorial);
        dice.pop_back();
    }
    return result;
}


void problem_240_solution(bool log) {
    int n_dice = 20;
    int n_top = 10;
    int sum = 70;
    int max_dice = 12;
    vector<long long> factorial(n_dice + 1, 1);
    for (int i = 1; i <= n_dice; i++) 
        factorial[i] = factorial[i - 1] * i;

    vector<int> dice;
    long long result = solve(0, n_dice, n_top, sum, max_dice, dice, factorial);
    if (log) 
        cout << result << endl;
}

#endif //PROJECT_EULER_PROBLEM240_H