#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>
#include <string>

using namespace std;


/* The TrieNode class represents a node in the Trie (prefix tree) data structure. 
 * Each node contains a character, a flag indicating whether it is the end of a word, 
 * and a map of child nodes. The TrieNode class also stores recipe data for the crafting system
 * via a RecipeData struct, which contains information about a recipe,
 * including ingredients, crafting time, and the tool required to craft the item.
 */

class TrieNode {
public:

    char data; 
    bool terminal;
    unordered_map<char, TrieNode*> children; 

    TrieNode(char data);
    ~TrieNode();

/* the RecipeData struct stores information about a recipe, including the required ingredients, 
crafting time, and tool. It's used to associate recipe data with the end nodes of the Trie. */
 
    struct RecipeData {
        unordered_map<string, int> ingredients;
        int craftingTime; 
        string toolRequired; 
    };


    bool isTerminal();
    void setTerminal(bool isEnd);
    TrieNode* getChild(char c);
    void addChild(char c);
    bool hasChild(char c);
    void setRecipeData(const unordered_map<string, int>& ingredients, int craftingTime, const string& tool);

    /* The getRecipeData method returns a pointer to the RecipeData struct associated with the TrieNode. */
    RecipeData* getRecipeData();

    /*RecipeData pointer below is used to store the recipe data associated with the end nodes of the Trie.*/ 

    RecipeData* recipeData;
};

#endif