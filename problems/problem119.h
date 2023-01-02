//
// Pratim Chowdhary on 10/20/22.
//

#ifndef PROJECT_EULER_PROBLEM119_H
#define PROJECT_EULER_PROBLEM119_H

#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

void problem_119_solution(bool log) {
    vector<long> v;
    for (long i = 2; i < 100; i++) {
        long p = i;
        for (int j = 1; j < 10; j++) {
            p *= i;
            if (p >= 10) {
                long sum = 0;
                long temp = p;
                while (temp > 0) {
                    sum += temp % 10;
                    temp /= 10;
                }
                if (sum == i) {
                    v.push_back(p);
                }
            }
        }
    }
    sort(v.begin(), v.end());
    if (log) cout << v[29] << endl;
}

#endif //PROJECT_EULER_PROBLEM119_H