#include "dfs.h"

void helper(Graph& graph, int node, std::vector<bool> &visited) {
    std::cout << node << " ";
    visited[node] = true;

    for (auto neighbor : graph.getNums()[node]) {
        if (!visited[neighbor]) {
            helper(graph, neighbor, visited);
        }
    }
}

void dfs(Graph& graph) {
    int source = 0;
    std::vector<bool> visited(graph.getVal(), false);

    helper(graph, source, visited);
}
