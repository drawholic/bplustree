#include "node.hpp"


Node::Node()
{

};


Node::Node(unsigned order): capacity(order)
{
    children.reserve(capacity);
    keys.reserve(capacity);
};

bool Node::is_leaf()
{
    return children.empty();
};