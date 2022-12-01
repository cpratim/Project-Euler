//
// Created by Pratim Chowdhary on 12/01/22.
//

#ifndef PROJECT_EULER_PROBLEM113_H
#define PROJECT_EULER_PROBLEM113_H

#include "iostream"

using namespace std;

long long increasing_cache[101][11] = {0};
long long decreasing_cache[101][11] = {0};



long long increasing(int i, int n, int m) {
    if (i == n - 1)
        return 1;
    if (m != -1 && increasing_cache[i][m] != 0) {
        return increasing_cache[i][m];
    }
        
    long long count = 0;
    if (m == -1) {
        for (int j = 0; j < 10; j++) {
            count += increasing(i, n, j);
        }
    } else {
        for (int j = 0; j <= m; j++) {
            count += increasing(i + 1, n, j);
        }
    }
    increasing_cache[i][m] = count;
    return count;
}

long long decreasing(int i, int n, int m) {
    if (i == n - 1)
        return 1;
    if (m != -1 && decreasing_cache[i][m] != 0)
        return decreasing_cache[i][m];
    long long count = 0;
    if (m == -1) {
        count += decreasing(i + 1, n, -1);
        for (int j = 0; j < 10; j++) {
            count += decreasing(i, n, j);
        }
    } else {
        for (int j = 0; j <= m; j++) {
            count += decreasing(i + 1, n, j);
        }
    }
    decreasing_cache[i][m] = count;
    return count;
}


void problem_113_solution(bool log) {
    
    int n = 100;
    long long solution = increasing(0, n, -1) + decreasing(0, n, -1) - 10 * (n-1) - 2;
    
    if (log) cout << solution << endl;
}


#endif //PROJECT_EULER_PROBLEM113_H
