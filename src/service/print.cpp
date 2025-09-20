#include "print.h"

void printEdge(const Graph& graph) {
    std::cout << "\nGraph Adjacency List:" << std::endl;
    std::cout << "---------------------" << std::endl;

    for (int i = 0; i < graph.getVal(); i++) {
        std::cout << i << " : ";

        if (graph.getNums()[i].empty()) {
            std::cout << "(no connections)";
        } else {
            for (auto neigh : graph.getNums()[i]) {
                std::cout << neigh << " ";
            }
        }

        std::cout << std::endl;
    }
    std::cout << "---------------------" << std::endl;
}
