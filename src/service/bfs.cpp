#include "bfs.h"

void bfs(Graph& graph) {
    std::queue<int> q;
    std::vector<bool> visited(graph.getVal(), false);

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (int neighbor : graph.getNums()[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}
