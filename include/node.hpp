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



    bool is_leaf();

};


#endif