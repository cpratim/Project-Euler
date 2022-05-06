//
// Created by Sonia Bendre on 5/6/22.
//

#ifndef PROJECT_EULER_PROBLEM8_H
#define PROJECT_EULER_PROBLEM8_H

#include "iostream"
#include "string"

using namespace std;

long find_max_product(string n, int window_size) {
    long window_prod = 1;
    int num_zero = 0;

    for (int i = 0; i < window_size; i++) {
        int pointer = (int) n[i] - '0';
        if (pointer == 0)
            num_zero += 1;
        else
            window_prod *= pointer;
    }
    long max_prod = num_zero == 0 ? window_prod : 0;

    for (int i = window_size; i < n.length(); i++) {
        int forward = (int) n[i] - '0';
        int backward = (int) n[i-window_size] - '0';
        if (backward == 0)
            num_zero --;
        else
            window_prod /= backward;
        if (forward == 0)
            num_zero ++;
        else
            window_prod *= forward;
        if (num_zero == 0) {
            max_prod = max(window_prod, max_prod);
        }
    }
    return max_prod;
};

void problem_8_solution(bool log) {
    string n = ""
       "73167176531330624919225119674426574742355349194934"
       "96983520312774506326239578318016984801869478851843"
       "85861560789112949495459501737958331952853208805511"
       "12540698747158523863050715693290963295227443043557"
       "66896648950445244523161731856403098711121722383113"
       "62229893423380308135336276614282806444486645238749"
       "30358907296290491560440772390713810515859307960866"
       "70172427121883998797908792274921901699720888093776"
       "65727333001053367881220235421809751254540594752243"
       "52584907711670556013604839586446706324415722155397"
       "53697817977846174064955149290862569321978468622482"
       "83972241375657056057490261407972968652414535100474"
       "82166370484403199890008895243450658541227588666881"
       "16427171479924442928230863465674813919123162824586"
       "17866458359124566529476545682848912883142607690042"
       "24219022671055626321111109370544217506941658960408"
       "07198403850962455444362981230987879927244284909188"
       "84580156166097919133875499200524063689912560717606"
       "05886116467109405077541002256983155200055935729725"
       "71636269561882670428252483600823257530420752963450";

    int window_size = 13;
    long max_prod = find_max_product(n, window_size);
    if (log) cout << max_prod << endl;
}

#endif //PROJECT_EULER_PROBLEM8_H
