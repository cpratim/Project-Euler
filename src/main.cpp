//
// Created by pratim on 4/19/22.
//

#include "iostream"
#include "string"
#include "../include/timer.h"

#include "../problems/problem1.h"

using namespace std;

int TRIALS = 100;

int main() {
    cout << "Problem 1 Solution: ";
    auto time = timer(problem_1_solution, TRIALS);
    cout << "Runtime: " + to_string(time) + " microseconds" << endl << endl;
};