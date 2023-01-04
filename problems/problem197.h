//
// Created by Jason Guo on 1/3/23.
//

#ifndef PROJECT_EULER_PROBLEM197_H
#define PROJECT_EULER_PROBLEM197_H

#include <cmath>
#include <iostream>
#include <iomanip>

double f(double x){
    return floor(std::pow(2, 30.403243784-x*x))*std::pow(10, -9);
}

void problem_197_solution(bool log){
    // This sequence eventually converges to two stable points
    // Bruh.
    const int n = 1000;
    double u_i = -1;
    int i = 0;
    while(i <= n){
        u_i = f(u_i);
        i++;
    }
    if (log) std::cout << std::setprecision(10) << u_i + f(u_i) << std::endl;

}

#endif //PROJECT_EULER_PROBLEM197_H
