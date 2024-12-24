#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <map>

class recipe {
	std::string name; //name of the recipe
	std::map<std::string, double> ingredients; //map of the ingredient name to its quantity

public:
	recipe(const std::string& n) :
		name(n) {}	//string name and empty ingredients map

	void addIngredient(std::string& ingredientName, double quantity) { //inserts an ingredient mapped to its quantity into the map
		ingredients[ingredientName] = quantity;	//key = ingredientName, value = quantity
	}

	std::map<std::string, double> getIngredients() {
		return ingredients;
	}

	const std::string& getName() const { return name; }
};


#endif

