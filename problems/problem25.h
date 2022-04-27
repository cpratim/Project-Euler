//
// Created by Karun Ram on 4/27/22.
//

#ifndef PROJECT_EULER_PROBLEM25_H
#define PROJECT_EULER_PROBLEM25_H

#include <iostream>
#include <cmath>

int problem_25_solution(bool log) {
    int n = 1000;
    float phi = (1 + sqrt(5)) / 2;
    float r = ((n-1) - log10(1/sqrt(5))) / log10(phi);
    int result = int(ceil(r));
    if (log) std::cout << result << std::endl;


}
#endif //PROJECT_EULER_PROBLEM25_H
