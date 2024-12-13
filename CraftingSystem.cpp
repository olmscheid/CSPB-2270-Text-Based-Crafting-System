#include "CraftingSystem.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std; 


CraftingSystem::CraftingSystem() {}

void CraftingSystem::addRecipe(const string& name, const unordered_map<string, int>& ingredients, int craftingTime, const string& toolRequired) {
    recipeTrie.insertRecipe(name, ingredients, craftingTime, toolRequired);
}

void CraftingSystem::addInventoryItem(const string& item, int quantity) {
    inventory.addItem(item, quantity);
}

void CraftingSystem::displayInventory() {
    inventory.display();
}

void CraftingSystem::listRecipes() {
    vector<string> recipes = recipeTrie.getAllRecipes();
    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    cout << "Available Recipes:" << endl;
    for (const string& recipe : recipes) {
        cout << "- " << recipe << endl;
    }
}

void CraftingSystem::listRequirements() {
    vector<string> recipes = recipeTrie.getAllRecipes();
    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    cout << "\nAll Recipe Requirements:\n" << endl;
    for (const string& recipeName : recipes) {
        TrieNode::RecipeData* recipe = recipeTrie.searchRecipe(recipeName);
        if (recipe) {
            cout << "- " << recipeName << ":\n";
            cout << "  Crafting Time: " << recipe->craftingTime << " seconds\n";
            cout << "  Tool Required: " << recipe->toolRequired << "\n";
            cout << "  Ingredients:\n";
            for (const auto& ingredient : recipe->ingredients) {
                cout << "    " << ingredient.first << ": " << ingredient.second << "\n";
            }
            cout << endl;
        }
    }
}

void CraftingSystem::craftItem(const string& item) {
    TrieNode::RecipeData* recipe = recipeTrie.searchRecipe(item);
    if (!recipe) {
        cout << "Recipe for " << item << " not found." << endl;
        return;
    }

    if (!inventory.hasItems(recipe->ingredients)) {
        cout << "Not enough ingredients to craft " << item << "." << endl;
        return;
    }

    inventory.consumeItems(recipe->ingredients);
    inventory.addItem(item, 1); 

    cout << "Crafted " << item << " successfully!" << endl;
}

void CraftingSystem::displayRecipeTrie() const {

    recipeTrie.display();

}
