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

Node* Node::get_child(unsigned key)
{
    return children[keys_comparison(key)];
};

unsigned Node::keys_comparison(unsigned key)
{
    unsigned i;
    for( i = 0; i < keys.size(); i++)
        if(key < keys[i]) break;
    return i;
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

    right->copy_children(children.begin()+ pivot, children.end());
    right->copy_keys(keys.begin()+pivot+1, keys.end());

    children.clear();
    keys.clear();    

    children.push_back(left);
    children.push_back(right);

    keys.push_back(pivot_key);

};


Node* Node::get_leaf(unsigned key)
{
    if(is_leaf()) return this;

    return get_child(key)->get_leaf(key);
};

void Node::copy_children(node_it a , node_it b)
{
    children.assign(a, b);
};

void Node::copy_keys(key_it a, key_it b)
{
    keys.assign(a, b);
};

void Node::insert(unsigned key)
{
    Node* leaf = get_leaf(key);
    
    leaf->push_node(key);   
    
    if(leaf->is_full()) leaf->split();
};


void Node::push_node(unsigned key)
{
    keys.insert(keys.begin()+keys_comparison(key), key);
};