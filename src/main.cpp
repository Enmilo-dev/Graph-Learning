#include "menu.h"
#include <iostream>

int main() {
    Graph* graph = nullptr;
    bool graphExists = false;
    int choice;

    std::cout << "Welcome to Graph Learning Tool!" << std::endl;

    do {
        showMenu();
        std::cin >> choice;
        handleChoice(choice, graph, graphExists);
    } while (choice != 6);

    if (graph) delete graph;
    return 0;
}
