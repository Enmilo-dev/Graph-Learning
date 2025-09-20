#include <iostream>
#include "graphBuilder.h"

void Graph::addEdge(int x, int y) {
    nums[x].push_back(y);
    nums[y].push_back(x);
}
