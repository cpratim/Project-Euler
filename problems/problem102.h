//
// Created by pratim on 5/6/22.
//

#ifndef PROJECT_EULER_PROBLEM102_H
#define PROJECT_EULER_PROBLEM102_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "../include/string_lib.h"

using namespace std;

bool contains_origin(vector<int> points) {
    bool cnx, cpx, cny, cpy;
    for (int i = 0; i < points.size(); i = i + 2) {
        int x1 = points[i];
        int y1 = points[i + 1];
        if (x1 == 0 && y1 == 0)
            return true;
        for (int j = i + 2; j < points.size(); j = j + 2) {
            double y_int, x_int;
            int x2 = points[j];
            int y2 = points[j + 1];
            if (x1 == x2) {
                y_int = x1;
            } else {
                double slope = (double) (y2 - y1) / (x2 - x1);
                y_int = slope * -x1 + y1;
                x_int = slope == 0 ? 0 : -y_int / slope;
            }
            if (x1 * x2 <= 0) {
                cny = y_int < 0 || cny;
                cpy = y_int > 0 || cpy;
            }
            if (y1 * y2 <= 0) {
                cnx = x_int < 0 || cnx;
                cpx = x_int > 0 || cpx;
            }
        }
        if (cnx and cpx and cny and cpy)
            return true;
    }
    return false;
}

void problem_102_solution(bool log) {
    string filename = "../misc/p102_triangles.txt";
    ifstream file(filename);
    string line;
    int count = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> str_points = split(line, ',');
        vector<int> points;
        for (const string& s : str_points) {
            points.push_back(stoi(s));
        }
        if (contains_origin(points))
            count++;
    }
    if (log) cout << count << endl;
}

#endif //PROJECT_EULER_PROBLEM102_H
