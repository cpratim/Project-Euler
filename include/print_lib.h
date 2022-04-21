//
// Created by pratim on 4/14/22.
//

#ifndef CEULER_PRINT_LIB_H
#define CEULER_PRINT_LIB_H

#include "iostream"
#include "vector"

using namespace std;

template <typename T>

void print_array(T *array) {
    cout << "[";
    for (int i = 0; i < sizeof(array) - 1; i++) {
        cout << array[i].toString() + ", ";
    }
    cout << to_string(array[-1]) + "]" << endl;
}

#endif //CEULER_PRINT_LIB_H
