#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node
{

    std::vector<Node*> children;
    std::vector<unsigned> keys;

    unsigned capacity;

public:
    Node();
    Node(unsigned);

    void insert(unsigned);
    Node* get_leaf(unsigned);
    bool is_leaf();
    bool is_full();
    void split();
};


#endif