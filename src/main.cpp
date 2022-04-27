//
// Created by pratim on 4/19/22.
//

#include "iostream"
#include "string"
#include "../include/timer.h"

#include "../problems/problem1.h"
#include "../problems/problem2.h"
#include "../problems/problem3.h"
#include "../problems/problem4.h"
#include "../problems/problem5.h"
#include "../problems/problem71.h"

using namespace std;

int EASY_TRIALS = 100;
int MEDIUM_TRIALS = 50;


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

    cout << "Problem 4 Solution: ";
    auto time4 = timer(problem_4_solution, MEDIUM_TRIALS);
    cout << "Runtime: " + to_string(time4) + " microseconds" << endl << endl;

    cout << "Problem 5 Solution: ";
    auto time5 = timer(problem_5_solution, EASY_TRIALS);
    cout << "Runtime: " + to_string(time5) + " microseconds" << endl << endl;

    cout << "Problem 71 Solution: ";
    auto time71 = timer(problem_71_solution, MEDIUM_TRIALS);
    cout << "Runtime: " + to_string(time71) + " microseconds" << endl << endl;
};
