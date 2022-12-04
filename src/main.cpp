//
// Created by Pratim and Karun on 4/19/22.
//

#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

#include "../include/timer.h"
#include "../include/string_lib.h"

#include "../problems/problem1.h"
#include "../problems/problem2.h"
#include "../problems/problem3.h"
#include "../problems/problem4.h"
#include "../problems/problem5.h"
#include "../problems/problem6.h"
#include "../problems/problem8.h"
#include "../problems/problem25.h"
#include "../problems/problem62.h"
#include "../problems/problem69.h"
#include "../problems/problem71.h"
#include "../problems/problem73.h"
#include "../problems/problem76.h"
#include "../problems/problem89.h"
#include "../problems/problem94.h"
#include "../problems/problem95.h"
#include "../problems/problem98.h"
#include "../problems/problem99.h"
#include "../problems/problem102.h"
#include "../problems/problem107.h"
#include "../problems/problem108.h"
#include "../problems/problem113.h"
#include "../problems/problem114.h"
#include "../problems/problem119.h"
#include "../problems/problem122.h"
#include "../problems/problem150.h"
#include "../problems/problem187.h"
#include "../problems/problem190.h"
#include "../problems/problem204.h"
#include "../problems/problem329.h"
#include "../problems/problem469.h"

using namespace std;

unordered_map<int, void (*)(bool)> problem_map {
        {1, problem_1_solution},
        {2, problem_2_solution},
        {3, problem_3_solution},
        {4, problem_4_solution},
        {5, problem_5_solution},
        {6, problem_6_solution},
        {8, problem_8_solution},
        {25, problem_25_solution},
        {62, problem_62_solution},
        {69, problem_69_solution},
        {71, problem_71_solution},
        {73, problem_73_solution},
        {76, problem_76_solution},
        {89, problem_89_solution},
        {94, problem_94_solution},
        {95, problem_95_solution},
        {98, problem_98_solution},
        {99, problem_99_solution},
        {102, problem_102_solution},
        {107, problem_107_solution},
        {108, problem_108_solution},
        {113, problem_113_solution},
        {114, problem_114_solution},
        {119, problem_119_solution},
        {122, problem_122_solution},
        {150, problem_150_solution},
        {187, problem_187_solution},
        {190, problem_190_solution},
        {204, problem_204_solution},
        {329, problem_329_solution},
        {469, problem_469_solution},
};

void run_problem(int problem_number, int trials) {
    cout << "Problem " + to_string(problem_number) + " Solution: ";
    auto time = timer(problem_map.find(problem_number)->second, trials);
    cout << "Average Runtime: " + to_string(time) + " microseconds" << endl << endl;
}

int main() {

    vector<int> sorted_problems;
    for (auto it: problem_map) {
        sorted_problems.push_back(it.first);
    }
    sort(sorted_problems.begin(), sorted_problems.end());

    cout << "Welcome to the Project Euler Shell!" << endl << endl;
    cout << "Commands:" << endl;
    cout << "list -> list all solved problems" << endl;
    cout << "quit -> quit shell" << endl;
    cout << "all -> Run all problems (1 trial each)" << endl;
    cout << "run [num] [trials] -> Run Problem [num] with [trials] Trials" << endl << endl;
    bool quit = false;
    while (not quit) {
        cout << "> ";
        string input;
        getline(cin, input);
        vector<string> splits = split(input, ' ');
        string command = splits[0];
        if (command == "list") {
            cout << "Solved Problems:";
            for (auto problem : sorted_problems) {
                cout << ", " + to_string(problem);
            }
            cout << endl << endl;
        } else if (command == "quit") {
            quit = true;
        } else if (command == "run") {
            int problem_number = stoi(splits[1]);
            if (not problem_map.contains(problem_number)) {
                cout << "Problem " + to_string(problem_number) + " is not solved yet!" << endl << endl;
            } else {
                try {
                    int trials = splits.size() == 2 ? 1 : stoi(splits[2]);
                    cout << "Running Problem " + to_string(problem_number) + " with " + to_string(trials) + " trials" << endl;
                    run_problem(problem_number, trials);
                } catch (const std::invalid_argument &e) {
                    cout << "Invalid argument!" << endl << endl;
                }
            }
        } else if (command == "all") {
            for (auto problem : sorted_problems) {
                run_problem(problem, 1);}
        } else {
            cout << "Invalid Command" << endl;
        }
    }
};
