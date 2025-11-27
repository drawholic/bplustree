#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"

class Tree
{
    unsigned order;
    Node* root;
public:
    Tree(unsigned);

    void insert(unsigned);
    void remove(unsigned);
    void search(unsigned);

};

#endif