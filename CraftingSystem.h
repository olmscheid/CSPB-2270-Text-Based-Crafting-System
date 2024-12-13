
#ifndef CRAFTINGSYSTEM_H
#define CRAFTINGSYSTEM_H

#include "Trie.h"
#include "Inventory.h"
#include <string> 
#include <unordered_map>

using namespace std;

/**
 * This class utilizes a Trie data structure to store and manage recipes, allowing for efficient searching and retrieval. 
 * It also maintains an inventory of items using the Inventory class. The CraftingSystem class provides methods to add new recipes, 
 * craft items based on available recipes and inventory, add items to the inventory, display the current inventory, list all available recipes, 
 * and list the requirements for crafting specific items. This class serves as the core component of the crafting system, 
 * ensuring that all crafting operations are performed accurately and efficiently.
 */

class CraftingSystem {
public:
    CraftingSystem();
    void addRecipe(const string& name, const unordered_map<string, int>& ingredients, int craftingTime, const string& toolRequired);
    void addInventoryItem(const string& item, int quantity);
    void displayInventory();
    void listRecipes();
    void listRequirements();
    void craftItem(const string& item);
    void displayRecipeTrie() const;
    

private: 

/* The private member variables include a Trie data structure to store and manage recipes, as well as an Inventory 
object to manage the player's inventory. This allows us to manage the inventory via the Inventory methods.
*/

    Trie recipeTrie;
    Inventory inventory;
};

#endif 