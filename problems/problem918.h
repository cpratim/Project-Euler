//
// Created by Pratim Chowdhary on 11/28/2024.
//


#ifndef PROJECT_EULER_PROBLEM918_H
#define PROJECT_EULER_PROBLEM918_H

#define LL long long

#include <iostream>
#include <unordered_map>


using namespace std;


LL a(LL n, unordered_map<LL, LL> & dp) {
    
    if (n == 0)
        return 4;
    if (n == 1)
        return 1;

    if (dp.find(n) != dp.end())
        return dp[n];
    
    LL r = n / 2;
    LL result = 0;
    if (n % 2 == 0)
        result = 2 * a(r, dp);
    else
        return a(r, dp) - 3 * a(r + 1, dp);
    dp[n] = result;
    return result;
    
}

LL S(LL n) {
    unordered_map<LL, LL> dp;
    return 4 - a(n / 2, dp);
}


void problem_918_solution(bool log) {

    LL n = 1000000000000;
    LL result = S(n);
    if (log) 
        cout << result << endl;
    return;
}


#endif //PROJECT_EULER_PROBLEM918_H