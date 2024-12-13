#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {

/* The Trie class represents a Trie (prefix tree) data structure that stores and manages recipes for the crafting system.
 * It provides methods to insert new recipes, search for specific recipes, and display the entire prefix tree.
 */ 
public:

/* the public member functions include a constructor and destructor for the Trie, as well as functions to insert a recipe, 
search for a recipe by name, get all recipes in the Trie, and display the Trie structure. These functions are used by the
CraftingSystem class to interact with the Trie data structure.*/

    Trie();
    ~Trie();
    void insert(const string& word);
    void insertRecipe(const string& name, const unordered_map<string, int>& ingredients, int craftingTime, const string& toolRequired);
    TrieNode::RecipeData* searchRecipe(const string& name);
    vector<string> getAllRecipes() const;
    void display() const;

private:

/*the private member variables include a root TrieNode pointer to the root of the Trie and helper functions to manage the Trie structure.
these are  used internally by the Trie class to insert, search, and display recipes in the prefix tree.*/

    TrieNode* root;
    void deleteSubtree(TrieNode* node);
    void displayHelper(TrieNode* node, string prefix, int depth) const;
    void getAllRecipesHelper(TrieNode* node, string prefix, vector<string>& recipes) const;
};

#endif 