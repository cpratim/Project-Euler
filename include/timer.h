//
// Created by pratim on 4/19/22.
//

#ifndef PROJECT_EULER_TIMER_H
#define PROJECT_EULER_TIMER_H

#include <chrono>

using namespace std;

double timer(auto (*func), int trials) {
    double total_time = 0;
    for (int i = 0; i < trials; i++) {
        auto start = chrono::high_resolution_clock::now();
        func(i == trials);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = duration_cast<chrono::microseconds>(stop - start);
        total_time += (double) duration.count();
    }
    return total_time / trials;
}

#endif //PROJECT_EULER_TIMER_H
