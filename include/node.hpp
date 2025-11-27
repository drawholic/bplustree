#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node;

typedef std::vector<Node*>::iterator node_it;
typedef std::vector<unsigned>::iterator key_it;

class Node
{

    std::vector<Node*> children;
    std::vector<unsigned> keys;

    unsigned capacity;

    Node* keys_comparison(unsigned);

public:
    Node();
    Node(unsigned);

    void insert(unsigned);
    Node* get_leaf(unsigned);
    bool is_leaf();
    bool is_full();
    void split();

    void copy_children(node_it, node_it);
    void copy_keys(key_it, key_it);
};


#endif