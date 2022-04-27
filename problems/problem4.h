//
// Created by Karun Ram on 4/26/22.
//

#ifndef PROJECT_EULER_PROBLEM4_H
#define PROJECT_EULER_PROBLEM4_H
#include <iostream>
#include <cmath>

bool isPalindrome(int n) {
    int rev = 0;
    int temp = n;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev == temp;
}

void problem_4_solution(bool log) {
    int numdigs = 3;
    long m = 0;
    for (int i = 1; i < pow(10, numdigs); i++) {
        for (int j = i; j < pow(10, numdigs); j++) {
            if (isPalindrome(i * j) && i * j > m) {
                m = i * j;
            }
        }
    }
    if (log) std::cout << m << std::endl;
}

#endif //PROJECT_EULER_PROBLEM4_H
