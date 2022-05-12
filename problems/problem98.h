//
// Created by Pratim, Sonia, Karun on 5/12/22.
//

#ifndef PROJECT_EULER_PROBLEM98_H
#define PROJECT_EULER_PROBLEM98_H

#include "unordered_map"
#include "unordered_set"
#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "fstream"
#include "tuple"
#include "cmath"
#include "../include/string_lib.h"

using namespace std;

bool check_anagram(const string& a, const string& b) {
    if (a.length() != b.length())
        return false;
    unordered_map<char, int> map;
    for (int i = 0; i < a.size(); i++) {
        map[a[i]] ++;
        map[b[i]] --;
    }
    for (auto itr: map) {
        if (itr.second != 0)
            return false;
    }
    return true;
}

long get_pattern_word(const string& word) {
    long pattern = 0;
    unordered_map<char, int> map;
    int index = 0;
    int size = word.size();
    for (int j = size - 1; j >= 0; j--) {
        char c = word[j];
        if (not map.contains(c)) {
            map[c] = index;
            index += 1;
        }
        pattern += map[c] * pow(10, size-j-1);
    }
    return pattern;
}

long get_pattern_int(long n) {
    long pattern = 0;
    unordered_map<int, int> map;
    int index = 0;
    int i = 0;
    while (n > 0) {

        int d = n % 10;
        if (not map.contains(d)) {
            map[d] = index;
            index += 1;
        }
        pattern += map[d] * pow(10, i);
        n = floor(n / 10);
        i++;
    }
    return pattern;
}

vector<tuple<string, string>> get_anagram_pairs(const string& filename,
                                                unordered_map<string, long>& pattern_map,
                                                unordered_set<long>& pattern_set) {
    ifstream file(filename);
    string line;
    getline(file, line);
    istringstream iss(line);
    vector<string> words = split(line, ',');
    for (string& word: words) {
        word = word.substr(1, word.length()-2);
    }
    vector<tuple<string, string>> anagram_pairs;
    for (int i = 0; i < words.size(); i++) {
        for (int j = i+1; j < words.size(); j++) {
            if (check_anagram(words[i], words[j])) {
                string word1 = words[i];
                string word2 = words[j];
                long pattern1 = get_pattern_word(word1);
                long pattern2 = get_pattern_word(word2);
                pattern_map[word1] = pattern1;
                pattern_map[word2] = pattern2;
                pattern_set.insert(pattern1);
                pattern_set.insert(pattern2);
                tuple<string, string> pair {word1, word2};
                anagram_pairs.push_back(pair);
            }
        }
    }
    return anagram_pairs;
}

void create_square_map(unordered_map<long, unordered_set<long>>& square_map,
                       unordered_set<long>& pattern_set) {
    long n = floor(10000 * sqrt(10)) - 1;
    while (n > 0) {
        long square = n * n;
        int n_digits = ceil(log10(square));
        long pattern = get_pattern_int(square);
        if (pattern_set.contains(pattern)) {
            if (not square_map.contains(pattern))
                square_map[pattern] = unordered_set<long> {};
            square_map[pattern].insert(square);
        }
        n--;
    }
}

long switch_digits(const string& word1, const string& word2, long square) {
    unordered_map<char, int> char_map;
    long switched = 0;
    int size = word1.size();
    for (int i = size-1; i >= 0; i--) {
        int d = square % 10;
        char c = word1[i];
        if (not char_map.contains(c))
            char_map[c] = d;
        square = floor(square / 10);
    }
    for (int i = 0; i < size; i++) {
        char c = word2[i];
        switched += char_map[c] * pow(10, size-i-1);
    }
    return switched;
}

void problem_98_solution(bool log) {
    unordered_map<string, long> pattern_map;
    unordered_set<long> pattern_set;
    vector<tuple<string, string>> anagram_pairs = get_anagram_pairs("../misc/p098_words.txt",
                                                                    pattern_map,
                                                                    pattern_set);
    unordered_map<long, unordered_set<long>> square_map;
    create_square_map(square_map, pattern_set);
    long largest = 0;
    for (tuple<string, string> pair: anagram_pairs) {
        string word1 = get<0>(pair);
        string word2 = get<1>(pair);
        long pattern1 = pattern_map[word1];
        long pattern2 = pattern_map[word2];
        for (long square: square_map[pattern1]) {
            long switched = switch_digits(word1, word2, square);
            if (square_map[pattern2].contains(switched)) {
                if (switched > largest)
                    largest = switched;
            }
        }
        for (long square: square_map[pattern2]) {
            long switched = switch_digits(word2, word1, square);
            if (square_map[pattern1].contains(switched)) {
                if (switched > largest)
                    largest = switched;
            }
        }
    }
    if (log) cout << largest << endl;
}


#endif //PROJECT_EULER_PROBLEM98_H
