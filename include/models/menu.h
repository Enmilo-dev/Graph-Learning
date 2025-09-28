#ifndef MENU_H
#define MENU_H

#include "graphBuilder.h"

void showMenu();
void handleChoice(int choice, Graph* graph, bool& graphExists);
Graph* createGraph();

#endif
