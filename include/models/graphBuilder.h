#pragma once
#include <iostream>
#include <list>

class Graph {
    int val;
    std::list<int> *nums;

public:
    Graph(int data) {
        this->val = data;
        nums = new std::list<int>[val];
    }
    void addEdge(int x, int y);

    int getVal() const { return val; }
    const std::list<int>* getNums() const { return nums; }
};
