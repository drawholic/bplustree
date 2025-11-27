#include "node.hpp"


Node::Node()
{

};


Node::Node(unsigned order): capacity(order)
{
    children.reserve(capacity);
    keys.reserve(capacity-1);
};

bool Node::is_leaf()
{
    return children.empty();
};

Node* Node::keys_comparison(unsigned key)
{
    unsigned i;
    for( i = 0; i < keys.size(); i++)
        if(key < keys[i]) break;
    return children[i];
};

bool Node::is_full()
{
    return children.size() >= capacity || keys.size() >= capacity - 1;
};

void Node::split()
{
    unsigned pivot = capacity / 2;
    Node* pivot_node = children[pivot];
    unsigned pivot_key = keys[pivot];

    Node* left = new Node(capacity);
    Node* right = new Node(capacity);
    
    left->copy_children(children.begin(), children.begin()+pivot);
    left->copy_keys(keys.begin(), keys.begin()+pivot);

    right->copy_children(children.begin()+ pivot + 1, children.end());
    right->copy_keys(keys.begin()+pivot+1, keys.end());

    children.clear();
    keys.clear();    

    children.push_back(pivot_node);
    keys.push_back(pivot_key);

};


