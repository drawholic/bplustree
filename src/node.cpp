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

Node* Node::keys_comparison(unsigned key, std::vector<unsigned>&)
{

};

bool Node::is_full()
{
    return children.size() >= capacity || keys.size() >= capacity - 1;
};