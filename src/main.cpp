//
// Created by pratim on 4/19/22.
//

#include "iostream"
#include "string"
#include "../include/timer.h"

#include "../problems/problem1.h"
#include "../problems/problem2.h"
#include "../problems/problem3.h"

using namespace std;

int EASY_TRIALS = 100;

int main() {
    cout << "Problem 1 Solution: ";
    auto time1 = timer(problem_1_solution, EASY_TRIALS);
    cout << "Runtime: " + to_string(time1) + " microseconds" << endl << endl;

    cout << "Problem 2 Solution: ";
    auto time2 = timer(problem_2_solution, EASY_TRIALS);
    cout << "Runtime: " + to_string(time2) + " microseconds" << endl << endl;

    cout << "Problem 3 Solution: ";
    auto time3 = timer(problem_3_solution, EASY_TRIALS);
    cout << "Runtime: " + to_string(time3) + " microseconds" << endl << endl;
};
