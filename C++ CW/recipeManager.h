#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H

#include<vector>
#include <fstream>
#include<map>

std::vector<class recipe> readIngredients(std::ifstream& in);

std::map<std::string, int> readOrders(std::ifstream& ord);

void processOrders(std::map<std::string, int> ord, std::vector<class recipe> rec);

#endif