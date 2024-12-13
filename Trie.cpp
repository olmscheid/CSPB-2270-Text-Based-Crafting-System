#include "Trie.h"
#include "TrieNode.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

Trie::Trie() {
    root = new TrieNode(' ');
}

Trie::~Trie() {
    deleteSubtree(root);
}

void Trie::deleteSubtree(TrieNode* node) {
    for (auto& child : node->children) {
        deleteSubtree(child.second);
    }
    delete node;
}

void Trie::insert(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode(ch);
        }
        node = node->children[ch];
    }
    node->setTerminal(true);
}

void Trie::insertRecipe(const string& name, const unordered_map<string, int>& ingredients, int craftingTime, const string& toolRequired) {
    TrieNode* node = root;
    for (char ch : name) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode(ch);
        }
        node = node->children[ch];
    }
    node->setTerminal(true);
    node->setRecipeData(ingredients, craftingTime, toolRequired);
}

TrieNode::RecipeData* Trie::searchRecipe(const string& name) {
    TrieNode* node = root;
    for (char ch : name) {
        if (node->children.find(ch) == node->children.end()) {
            return nullptr;
        }
        node = node->children[ch];
    }
    if (node->isTerminal()) {
        return node->getRecipeData();
    }
    return nullptr;
}

vector<string> Trie::getAllRecipes() const {
    vector<string> recipes;
    getAllRecipesHelper(root, "", recipes);
    return recipes;
} 

void Trie::getAllRecipesHelper(TrieNode* node, string prefix, vector<string>& recipes) const {
    if (node->isTerminal()) {
        recipes.push_back(prefix);
    }
    for (auto it : node->children) {
        getAllRecipesHelper(it.second, prefix + it.first, recipes);
    }
}

void Trie::display() const {
    displayHelper(root, "", 0);
}

void Trie::displayHelper(TrieNode* node, string prefix, int depth) const {
    if (node->isTerminal()) {
        cout << prefix << " (depth: " << depth << ", terminal)" << endl;
    } else {
        cout << prefix << " (depth: " << depth << ")" << endl;
    }
    for (auto it : node->children) {
        displayHelper(it.second, prefix + it.first, depth + 1);
    }
}