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
#include "../problems/problem25.h"
#include "../problems/problem71.h"
#include "../problems/problem94.h"
#include "../problems/problem122.h"
#include "../problems/problem187.h"
#include "../problems/problem190.h"

using namespace std;

int EASY_TRIALS = 100;
int MEDIUM_TRIALS = 50;
int INTERMEDIATE_TRIALS = 10;
int HARD_TRIALS = 2;


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

    cout << "Problem 25 Solution: ";
    auto time6 = timer(problem_25_solution, EASY_TRIALS);
    cout << "Runtime: " + to_string(time6) + " microseconds" << endl << endl;

    cout << "Problem 71 Solution: ";
    auto time71 = timer(problem_71_solution, MEDIUM_TRIALS);
    cout << "Runtime: " + to_string(time71) + " microseconds" << endl << endl;

    cout << "Problem 94 Solution: ";
    auto time94 = timer(problem_94_solution, MEDIUM_TRIALS);
    cout << "Runtime: " + to_string(time94) + " microseconds" << endl << endl;

    cout << "Problem 122 Solution: ";
    auto time122 = timer(problem_122_solution, INTERMEDIATE_TRIALS);
    cout << "Runtime: " + to_string(time122) + " microseconds" << endl << endl;

    cout << "Problem 187 Solution: ";
    auto time187 = timer(problem_187_solution, HARD_TRIALS);
    cout << "Runtime: " + to_string(time187) + " microseconds" << endl << endl;

    cout << "Problem 190 Solution: ";
    auto time190 = timer(problem_190_solution, EASY_TRIALS);
    cout << "Runtime: " + to_string(time190) + " microseconds" << endl << endl;
};
