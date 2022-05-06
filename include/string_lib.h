//
// Created by pratim on 5/6/22.
//

#ifndef PROJECT_EULER_STRING_LIB_H
#define PROJECT_EULER_STRING_LIB_H

#include <sstream>
#include "string"
#include "vector"

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

#endif //PROJECT_EULER_STRING_LIB_H
