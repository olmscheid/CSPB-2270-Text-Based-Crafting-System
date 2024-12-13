#ifndef INVENTORY_H
#define INVENTORY_H

/*I learned aobut ifndef and define from https://www.learncpp.com/cpp-tutorial/header-guards/
what they do is they prevent the header file from being included more than once in the same file.*/

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

/* The inventory class represents the player's inventory in the crafting system.
 * It stores the items and their quantities that the player currently possesses.
 */

class Inventory {
public:

/*The addItem, hasItems, consumeItems, and display functions are public so that
they can be accessed by the CraftingSystem class to manage the player's inventory.*/

    void addItem(const string& item, int quantity);
    bool hasItems(const unordered_map<string, int>& requiredItems) const;
    void consumeItems(const unordered_map<string, int>& requiredItems);
    void display() const;

private: 
/* Map to store items and their quantities. This is private because it should only 
be accessed internally by the Inventory class.*/ 

    unordered_map<string, int> items;
};

#endif
