#include "menu.h"
#include "print.h"
#include "bfs.h"
#include "dfs.h"
#include "cycle.h"
#include <iostream>

void showMenu() {
    std::cout << "\n=== Graph Operations Menu ===" << std::endl;
    std::cout << "1. Create Graph" << std::endl;
    std::cout << "2. Print Adjacency List" << std::endl;
    std::cout << "3. DFS Traversal" << std::endl;
    std::cout << "4. BFS Traversal" << std::endl;
    std::cout << "5. Check for Cycles" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

Graph* createGraph() {
    int numVertices, numEdges;

    std::cout << "Enter number of vertices: ";
    std::cin >> numVertices;

    if (numVertices <= 0) {
        std::cout << "Invalid input!" << std::endl;
        return nullptr;
    }

    Graph* graph = new Graph(numVertices);

    std::cout << "Enter number of edges: ";
    std::cin >> numEdges;

    if (numEdges < 0) {
        std::cout << "Invalid input!" << std::endl;
        delete graph;
        return nullptr;
    }

    if (numEdges > 0) {
        std::cout << "Enter edges (vertices 0-" << (numVertices - 1) << "):" << std::endl;

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

            graph->addEdge(source, destination);
        }
    }

    std::cout << "Graph created successfully!" << std::endl;
    return graph;
}

void handleChoice(int choice, Graph* graph, bool& graphExists) {
    switch (choice) {
        case 1:
            if (graph) delete graph;
            graph = createGraph();
            graphExists = (graph != nullptr);
            break;

        case 2:
            if (!graphExists) {
                std::cout << "Please create a graph first!" << std::endl;
            } else {
                std::cout << "\nAdjacency List:" << std::endl;
                printEdge(*graph);
            }
            break;

        case 3:
            if (!graphExists) {
                std::cout << "Please create a graph first!" << std::endl;
            } else {
                std::cout << "DFS: ";
                dfs(*graph);
                std::cout << std::endl;
            }
            break;

        case 4:
            if (!graphExists) {
                std::cout << "Please create a graph first!" << std::endl;
            } else {
                std::cout << "BFS: ";
                bfs(*graph);
                std::cout << std::endl;
            }
            break;

        case 5:
            if (!graphExists) {
                std::cout << "Please create a graph first!" << std::endl;
            } else {
                if (isCycle(*graph)) {
                    std::cout << "Cycle detected in the graph!" << std::endl;
                } else {
                    std::cout << "No cycle found in the graph." << std::endl;
                }
            }
            break;

        case 6:
            std::cout << "Goodbye!" << std::endl;
            break;

        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
    }
}
