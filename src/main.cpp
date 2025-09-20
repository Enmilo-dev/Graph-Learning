#include <iostream>
#include "graphBuilder.h"
#include "print.h"

int main() {
    int numVertices, numEdges;

    std::cout << "Enter number of vertices: ";
    std::cin >> numVertices;

    if (numVertices <= 0) {
        std::cout << "Invalid input! Please enter a positive number." << std::endl;
        return 1;
    }

    Graph graph(numVertices);

    std::cout << "Enter number of edges: ";
    std::cin >> numEdges;

    if (numEdges < 0) {
        std::cout << "Invalid input! Edges cannot be negative." << std::endl;
        return 1;
    }

    if (numEdges > 0) {
        std::cout << "\nEnter edges (vertices 0-" << (numVertices - 1) << "):" << std::endl;

        for (int i = 0; i < numEdges; i++) {
            int source, destination;

            std::cout << "Edge " << (i + 1) << ": ";
            std::cin >> source >> destination;

            if (source < 0 || source >= numVertices ||
                destination < 0 || destination >= numVertices) {
                std::cout << "Invalid vertices! Try again." << std::endl;
                i--;
                continue;
            }

            graph.addEdge(source, destination);
        }
    }

    std::cout<< "Do you want to print the adjacency list? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        printEdge(graph);
    } else {
        std::cout << "Exiting without printing adjacency list." << std::endl;
    }

    return 0;
}
