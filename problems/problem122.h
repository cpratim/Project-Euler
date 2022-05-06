//
// Created by Karun Ram, Pratim Chowdhary on 5/4/22.
//

#ifndef PROJECT_EULER_PROBLEM122_H
#define PROJECT_EULER_PROBLEM122_H

#include "iostream"
#include "unordered_set"
#include "unordered_map"
#include "queue"

using namespace std;

struct QueueElement {
    int sum;
    unordered_set<int> found;
    int count;
};

void find_min_multiplications(int n, unordered_map<int, int> &map) {
    if (n == 1)
        return;
    queue<QueueElement> queue;
    queue.push({1, unordered_set<int>({1}), 0});
    while (not queue.empty()) {
        QueueElement element = queue.front();
        queue.pop();
        unordered_set<int>::iterator itr;
        for (itr = element.found.begin(); itr != element.found.end(); itr++) {
            int inc_sum = *itr + element.sum;
            int inc_count = element.count + 1;
            if (inc_sum == n) {
                map[inc_sum] = inc_count;
                return;
            }
            if (inc_sum < n and (not map.contains(inc_sum) or inc_count <= map.find(inc_sum)->second)) {
                map.insert({inc_sum, inc_count});
                unordered_set<int> inc_found = element.found;
                inc_found.insert(inc_sum);
                QueueElement new_element = {inc_sum, inc_found, inc_count};
                queue.push(new_element);
            }
        }
    }
}

void problem_122_solution(bool log) {
    int n = 200;
    int track = n;
    int sum = 0;
    unordered_map<int, int> map;
    while (map.size() != n - 1) {
        if (not map.contains(track))
            find_min_multiplications(track, map);
        track--;
    }
    for (auto & itr : map) {
        sum += itr.second;
    }
    if (log) cout << sum << endl;
}

#endif //PROJECT_EULER_PROBLEM122_H
