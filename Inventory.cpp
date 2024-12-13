#include "Inventory.h"

using namespace std;


void Inventory::addItem(const string& item, int quantity) {
// If the item is not already in the inventory, add it with the specified quantity
    items[item] += quantity;
}

// hasItems checks if the inventory contains the required items with the specified quantities
bool Inventory::hasItems(const unordered_map<string, int>& requiredItems) const {
    for (const auto& [item, quantity] : requiredItems) { 
        if (items.find(item) == items.end() || items.at(item) < quantity) {
            return false;
        }
    }
    return true;
} 

void Inventory::consumeItems(const unordered_map<string, int>& requiredItems) {

// Remove the required items with the specified quantities from the inventory
    for (const auto& [item, quantity] : requiredItems) {
        items[item] -= quantity;
    }
}

void Inventory::display() const {
    cout << "Inventory:" << endl;
    for (const auto& [item, quantity] : items) {
        cout << "- " << item << ": " << quantity << endl;
    }
}

