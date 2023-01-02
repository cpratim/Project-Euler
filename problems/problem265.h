//
// Created by Jason Guo on 1/1/23.
//

#ifndef PROJECT_EULER_PROBLEM265_H
#define PROJECT_EULER_PROBLEM265_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <cmath>
#include <functional>

void problem_265_solution(bool log){
    const int N = 5;

    const int S = 1<<N;

    auto init = std::bitset<S>();

    auto seen = std::unordered_set<std::bitset<N>>();

    auto a = std::bitset<N>(0);
    seen.insert(a);
    // std::cout << a << "\n";

    unsigned long long solution = 0;
    unsigned long long *sol = &solution;

    auto splice = [](std::bitset<S> source, int left){
        auto ret = std::bitset<N>();
        for (int i = left; i < left + N; i++)
            ret[i - left] = source[i];
        return ret;
    };

    std::function<void(std::bitset<S>, int)> backtrack;

    backtrack = [&seen, sol, &splice, &backtrack](std::bitset<S> bitarray, int idx){
        if (idx == S - N + 1) {
            for (int i = 0; i < N - 1; i++){
                auto a = std::bitset<N>();
                int l = 0;
                for (int j = idx + i; j < S; j++){
                    a[j - idx - i] = bitarray[j];
                    l++;
                }
                for (int j = 0; j < i + 1; j++)
                    a[l + j] = bitarray[j];

                if (seen.find(a) != seen.end()){
                    return;
                }
            }
            
            auto reverse = bitarray;
            for(std::size_t i = 0; i < S/2; i++) {
                bool t = reverse[i];
                reverse[i] = reverse[S-i-1];
                reverse[S-i-1] = t;
            }
            *sol += reverse.to_ullong();
            return;
        }

        bitarray[idx + N - 1] = 0;
        auto x = splice(bitarray, idx);
        if (seen.find(x) == seen.end()){
            seen.insert(x);
            backtrack(bitarray, idx + 1);
            seen.erase(x);
        }

        bitarray[idx + N - 1] = 1;
        x = splice(bitarray, idx);
        if (seen.find(x) == seen.end()){
            seen.insert(x);
            backtrack(bitarray, idx + 1);
            seen.erase(x);
        }

    };

    backtrack(init, 1);
    if (log) std::cout << solution << std::endl;

}


#endif //PROJECT_EULER_PROBLEM265_H