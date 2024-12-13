#include "CraftingSystem.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    CraftingSystem craftingSystem; 

    // Preload
    craftingSystem.addRecipe("Potion", { {"Herbs", 2}, {"Water", 1} }, 2, "Alchemy Table");
    craftingSystem.addRecipe("Phoenix Down", { {"Feather", 1}, {"Magic Dust", 1} }, 4, "Enchanted Workbench");
    craftingSystem.addRecipe("Iron Sword", { {"Iron Ingot", 2}, {"Wood", 1} }, 5, "Forge");
    craftingSystem.addRecipe("Iron Shield", { {"Iron Ingot", 3}, {"Wood", 2} }, 6, "Forge"); 
    craftingSystem.addRecipe("Elixir", { {"Crystal Shard", 1}, {"Herbs", 3}, {"Magic Dust", 2} }, 6, "Alchemy Table");
    craftingSystem.addRecipe("Mythril Armor", { {"Mythril Ore", 3}, {"Leather", 2} }, 8, "Forge");
    craftingSystem.addRecipe("Adamant Shield", { {"Adamantite", 2}, {"Magic Dust", 1} }, 10, "Forge");
    craftingSystem.addRecipe("Holy Lance", { {"Dragon Fang", 1}, {"Holy Water", 2} }, 12, "Enchanted Workbench");
    craftingSystem.addRecipe("Fire Rod", { {"Fire Crystal", 1}, {"Wood", 1} }, 7, "Enchanted Workbench");
    craftingSystem.addRecipe("Ice Sword", { {"Ice Crystal", 1}, {"Iron Ingot", 1} }, 8, "Forge");
    craftingSystem.addRecipe("Wind Harp", { {"Wind Crystal", 1}, {"Wood", 2} }, 9, "Alchemy Table");

    // Preload inventory
    craftingSystem.addInventoryItem("Herbs", 5);
    craftingSystem.addInventoryItem("Water", 2);
    craftingSystem.addInventoryItem("Feather", 1);
    craftingSystem.addInventoryItem("Magic Dust", 3);
    craftingSystem.addInventoryItem("Iron Ingot", 5);
    craftingSystem.addInventoryItem("Wood", 3);
    craftingSystem.addInventoryItem("Leather", 2);

    cout << "Welcome to the RPG Crafting System (TM)!" << endl;

    
    while (true) {
        craftingSystem.displayInventory();

        cout << "\nWhat would you like to do? (Type 'list' to view available recipes, 'requirements' to view all requirements, 'trie' to display the prefix tree, or 'exit' to quit)" << endl;
        string input;
        getline(cin, input);

        if (input == "exit") {
            cout << "Exiting the crafting system. Goodbye!" << endl;
            break;
        }

        if (input == "list") {
            craftingSystem.listRecipes();
            continue;
        }

        if (input == "requirements") {
            craftingSystem.listRequirements();
            continue;
        }

        if (input == "trie") {
            cout << "Prefix Tree:" << endl;
            craftingSystem.displayRecipeTrie();
            continue;
        }

        if (input.empty()) {
            cout << "Please enter a valid item name or command." << endl;
            continue;
        }

        craftingSystem.craftItem(input);
    }

    return 0;
}