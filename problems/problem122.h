//
// Created by Pratim Chowdhary on 5/4/22.
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

int find_min_multiplications(int n) {
    if (n == 1) return 0;
    queue<QueueElement> queue;
    unordered_map<int, int> map;
    QueueElement init = {1, unordered_set<int>({1}), 0};
    queue.push(init);
    while (!queue.empty()) {
        QueueElement element = queue.front();
        queue.pop();
        unordered_set<int>::iterator itr;
        for (itr = element.found.begin(); itr != element.found.end(); itr++) {
            int inc_sum = *itr + element.sum;
            int inc_count = element.count + 1;
            if (inc_sum == n) return inc_count;
            if (inc_sum < n and (map.find(inc_sum) == map.end() or inc_count <= map.find(inc_sum)->second)) {
                map.insert({inc_sum, inc_count});
                unordered_set<int> inc_found = element.found;
                inc_found.insert(inc_sum);
                QueueElement new_element = {inc_sum, inc_found, inc_count};
                queue.push(new_element);
            }
        }
    }
    return 0;
}

void problem_122_solution(bool log) {
    int sum = 0;
    for (int i = 1; i <= 200; i++) {
        sum += find_min_multiplications(i);
    }
    if (log) cout << sum << endl;
}

#endif //PROJECT_EULER_PROBLEM122_H
