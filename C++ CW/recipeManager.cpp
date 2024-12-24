#include "recipeManager.h"
#include "recipe.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<recipe> readIngredients(ifstream& in) { // reads ingredients.txt and returns a vector of recipe objects which contain their ingredients 
	string name, ingredient;				   // which are added through reading the text file
	double quantity;
	vector<recipe> recipes;
	while (in >> name >> ingredient >> quantity) {
		bool recipeFound = false;
		for (auto& recipe : recipes) {
			if (recipe.getName() == name) { // if recipe is already in vector
				recipe.addIngredient(ingredient, quantity);
				recipeFound = true;
			}
		} if (recipeFound == false) { //if recipe is not already in vector
			recipe r(name);
			r.addIngredient(ingredient, quantity);
			recipes.push_back(r); //adds recipe to vector
		}
	}
	in.close();
	return recipes;
}

map<string, int> readOrders(ifstream &ord) { // reads orders.txt and produces a map based off it, condensing it so there are no duplicate orders
	string name;
	int quantity;
	map<string, int> orders;

	while (ord >> name >> quantity) {
		bool orderFound = false;
		for (auto& keyValue : orders) {
			if (keyValue.first == name) {
				keyValue.second += quantity; //if order item already exists just update quantity
				orderFound = true;
			}
		} if (orderFound == false) {
			orders[name] = quantity;
		}
	}
	ord.close();
	return orders;
}

void processOrders(map<string, int> orders, vector<recipe> recipes) {
	map<string, float> finalIngredients; //map of ingredients to total quantity based off all orders
	bool ingredientFound = false;
	for (auto& order : orders) {
		for (auto& recipe : recipes) {			//"You may assume that the recipes named occur in ingredients.txt"
			if (recipe.getName() == order.first) {
				auto ingredients = recipe.getIngredients();
				for (auto& ingredient : ingredients) {
					auto it = finalIngredients.find(ingredient.first);
					if (it != finalIngredients.end()) {
						it->second += (ingredient.second * order.second); //if ingredient is already in vector then add the new quantity to it
					}
					else {
						finalIngredients[ingredient.first] = (ingredient.second) * order.second;
					}
				}
			}
		}
														
	}
	for (auto& ingredient : finalIngredients) {
		cout << ingredient.first << " " << ingredient.second << '\n'; //displays total ingredients
	}
}