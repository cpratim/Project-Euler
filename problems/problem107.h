//
// Created by Pratim on 11/25/22.
//

#ifndef PROJECT_EULER_PROBLEM107_H
#define PROJECT_EULER_PROBLEM107_H

#include "unordered_map"
#include "unordered_set"
#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "fstream"
#include "tuple"
#include "cmath"
#include "stack"
#include "queue"
#include "../include/string_lib.h"

using namespace std;

void add_edge(unordered_map<int, vector<int>>& graph, int u, int v) {
    if (graph.find(u) == graph.end()) {
        graph[u] = vector<int>();
    }
    if (graph.find(v) == graph.end()) {
        graph[v] = vector<int>();
    }
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void remove_edge(unordered_map<int, vector<int>>& graph, int u, int v) {
    graph[u].pop_back();
    graph[v].pop_back();
}

bool find_cycle(int v, int p, unordered_map<int, vector<int>> &graph, vector<bool> &visited) {
    visited[v] = true;
    for (int n: graph[v]) {
        if (!visited[n]) {
            if (find_cycle(n, v, graph, visited))
                return true;
        } else if (p != n) {
            return true;
        }
    }
    return false;
}

bool has_cycle(unordered_map<int, vector<int>> &graph, int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i] && find_cycle(i, -1, graph, visited)) {
            return true;
        }
    }
    return false;
}

void read_edges(string filename, priority_queue<tuple<int, int, int>> &edges) {
    ifstream file(filename);
    string line;
    int i = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> tokens = split(line, ',');
        for (int j = 0; j < tokens.size(); j++) {
            if (tokens[j] != "-") {
                edges.push(make_tuple(-stoi(tokens[j]), i, j));
            }
        }
        i++;
    }
}

void problem_107_solution(bool log) {
    unordered_map<int, vector<int>> graph;
    priority_queue<tuple<int, int, int>> edges;
    read_edges("misc/p107_network.txt", edges);
    int V = 40;
    long total = 0;
    long cost = 0;
    while (!edges.empty()) {
        tuple<int, int, int> edge = edges.top();
        add_edge(graph, get<1>(edge), get<2>(edge));
        if (has_cycle(graph, V)) {
            remove_edge(graph, get<1>(edge), get<2>(edge));
            
        } else {
            cost += abs(get<0>(edge));
        }
        total += abs(get<0>(edge));
        edges.pop();
    }
    if (log) cout << (total / 2) - cost << endl;
}


#endif //PROJECT_EULER_PROBLEM107_H