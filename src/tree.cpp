#include "tree.hpp"


Tree::Tree(unsigned order): order(order) {
    root = nullptr;
};

void Tree::remove(unsigned key)
{};

void Tree::insert(unsigned key)
{
    if(root == nullptr)
    {
        root = new Node(order);
        root->insert(key);
    }else{
        Node* leaf = root->get_leaf(key);
        
    
    };

};

void Tree::search(unsigned key){};