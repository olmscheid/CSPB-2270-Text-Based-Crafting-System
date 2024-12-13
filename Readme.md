## Overview

Crafting System Project v 1.0

This project implements a simple crafting system using a Trie (prefix tree) data structure. 
The system allows users to add recipes, manage inventory, and craft items. 

Video Tutorial: https://drive.google.com/file/d/14tZSmHg0ZFNxF__9lyi7wmhuqdyWq1qA/view?usp=drive_link

## Deviations from my Project Proposal

In my original project proposal, I presented the Trie and Directed Acyclic Graph as two seperate
and distinct items. I also was initially thinking I would use a topological search to craft items
with dependencies/particular order.

I decided against this approach because I realized that if I'm crafting something in a game,
generally there isn't a need for wood before iron or iron before wood if it's just required to
have a particular set of items to create something.

Also, I'm an idiot that was thinking that DAG was a completely separate thing without remembering that
a prefix tree (trie) is a type of DAG. "All trees are DAGs but not all DAGs are Trees". I think?


## References

https://www.learncpp.com/

https://en.wikipedia.org/wiki/Trie

https://www.algotree.org/algorithms/trie/

https://www.youtube.com/watch?v=3CbFFVHQrk4&t=450s

Zybooks

HW-05-B-TREE



## Files

MAIN

main.cpp - Initializes the crafting system, adds recipes, preloads inventory, and provides an 
interactive text-based menu for user interaction.

CRAFTING SYSTEM

CraftingSystem.h - Declares methods for adding recipes, managing inventory, displaying inventory,
listing recipes, listing recipe requirements, crafting items, and displaying the recipe trie.
CraftingSystem.cpp - Implements methods for adding recipes, managing inventory, displaying 
inventory, listing recipes, listing recipe requirements, crafting items, and displaying the 
recipe trie.

INVENTORY

Inventory.h - Declares methods for the player's inventory in the crafting system. Allows users to
store items and their quantities that the player currently possesses.
Inventory.cpp - Implements methods for addItems, Display, consumeItems, hasItems.

TRIE

Trie.h  - Declares methods for inserting words, inserting recipes, searching for recipes, 
retrieving all recipes, and displaying the trie.
Trie.cpp - Implements methods for inserting words, inserting recipes, searching for 
recipes, retrieving all recipes, and displaying the trie.
 
TRIENODES

TrieNode.h - Declares the TrieNode class, which represents a node in the trie. Includes 
the RecipeData struct, which stores information about a recipe, including ingredients, 
crafting time, and the tool required.
TrieNode.cpp - Implements methods for managing trie nodes, including adding children, 
checking for children, setting and getting recipe data, and managing terminal nodes.

## How to Run

How to Run
Compile the project:

$ g++ -o main main.cpp CraftingSystem.cpp Trie.cpp TrieNode.cpp Inventory.cpp -I. -std=c++17

Run the executable:

./main