#include "TrieNode.h"

// Constructor for TrieNode with specified character data and default terminal state of false and recipeData as nullptr
TrieNode::TrieNode(char data) : data(data), terminal(false), recipeData(nullptr) {}

// Destructor for TrieNode that deletes the recipeData if it exists and recursively deletes all child nodes
TrieNode::~TrieNode() {
    if (recipeData) {
        delete recipeData;
    }
    for (auto& child : children) {
        delete child.second;
    }
}

bool TrieNode::isTerminal() {
    return terminal; 
}

void TrieNode::setTerminal(bool isEnd) {
    terminal = isEnd;
}

TrieNode* TrieNode::getChild(char c) {
    if (children.find(c) != children.end()) {
        return children[c];
    }
    return nullptr;
}

void TrieNode::addChild(char c) {
    if (children.find(c) == children.end()) {
        children[c] = new TrieNode(c);
    }
}

bool TrieNode::hasChild(char c) {
    return children.find(c) != children.end();
}

void TrieNode::setRecipeData(const unordered_map<string, int>& ingredients, int craftingTime, const string& tool) {
    if (!recipeData) {
        recipeData = new RecipeData{ingredients, craftingTime, tool};
    }
}

TrieNode::RecipeData* TrieNode::getRecipeData() {
    return recipeData;
}