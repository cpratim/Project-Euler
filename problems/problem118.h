//
// Pratim Chowdhary on 12/10/22.
//

#ifndef PROJECT_EULER_PROBLEM118_H
#define PROJECT_EULER_PROBLEM118_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool is_prime_cache(long n, unordered_map<long, bool> &prime_map) {
    if (prime_map.find(n) != prime_map.end()) {
        return prime_map[n];
    }
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            prime_map[n] = false;
            return false;
        }
    }
    prime_map[n] = true;
    return true;
}

vector<string> get_permutations(string s) {
    vector<string> v;
    if (s.length() == 1) {
        v.push_back(s);
        return v;
    }
    for (int i = 0; i < s.length(); i++) {
        string temp = s;
        temp.erase(i, 1);
        vector<string> v2 = get_permutations(temp);
        for (int j = 0; j < v2.size(); j++) {
            v.push_back(s[i] + v2[j]);
        }
    }
    return v;
}

void generate_products(string permutation, long product, unordered_set<long> &products, unordered_map<long, bool> &prime_map) {
    if (permutation.length() == 0) {
        products.insert(product);
        return;
    }
    for (int i = 1; i <= permutation.length(); i++) {
        string temp = permutation;
        long n = stol(temp.substr(0, i));
        if (is_prime_cache(n, prime_map)) {
            temp.erase(0, i);
            generate_products(temp, product * n, products, prime_map);
        }
    }
}

void problem_118_solution(bool log) {
    string digits = "123456789";
    vector<string> v = get_permutations(digits);
    unordered_set<long> products;
    unordered_map<long, bool> prime_map;
    for (int i = 0; i < v.size(); i++) {
        generate_products(v[i], 1, products, prime_map);
    }
    if (log) cout << products.size() << endl;
}


#endif //PROJECT_EULER_PROBLEM118_H