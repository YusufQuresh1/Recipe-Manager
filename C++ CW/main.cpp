#include "recipe.h"
#include "recipeManager.h"

using namespace std;

int main() {

	ifstream ingredients("ingredients.txt");
	ifstream orders("orders.txt");

	vector<recipe> recipes = readIngredients(ingredients); //recipes = vector of each unique recipe from ingredients.txt
	map<string, int> finalOrders = readOrders(orders); // finalOrders = map of orders from orders.txt to their total quantities
	processOrders(finalOrders, recipes); // outputs total quantity of each ingredient based off the finalOrders

	return 0;
}
