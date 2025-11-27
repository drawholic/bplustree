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


