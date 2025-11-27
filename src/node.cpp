#include "node.hpp"


Node::Node()
{

};


Node::Node(unsigned order): capacity(order)
{
    children.reserve(capacity);
    keys.reserve(capacity+1);
};

bool Node::is_leaf()
{
    return children.empty();
};