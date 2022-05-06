#include "iostream"
#include "string"
#include "../include/timer.h"

#include "../problems/problem190.h" //include the solution you want to test

using namespace std;

int EASY_TRIALS = 100;
int MEDIUM_TRIALS = 50;
int INTERMEDIATE_TRIALS = 10;
int HARD_TRIALS = 2;


int main() {
    auto time = timer(problem_190_solution, EASY_TRIALS); //change to function name from solution
    cout << "Runtime: " + to_string(time) + " microseconds" << endl << endl;
};
