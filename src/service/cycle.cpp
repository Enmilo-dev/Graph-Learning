#include "cycle.h"

bool isCycleUndDFS (Graph& graph, int src, int parent, std::vector<bool>&visited) {
    visited[src] = true;
    std::list<int> neighbors = graph.getNums()[src];

    for (auto v: neighbors) {
        if (!visited[v]) {
            if (isCycleUndDFS(graph, v, src, visited)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }

    return false;
}


bool isCycle(Graph& graph) {
    std::vector<bool> visited(graph.getVal(), false);

    for (int i = 0; i < graph.getVal(); i++) {
        if (!visited[i]) {
            if (isCycleUndDFS(graph, i, -1, visited)) {
                return true;
            }
        }
    }
    return false;
}
