#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <iostream>

struct Node {
    std::string name;
    std::shared_ptr<Node> spNext;
    std::weak_ptr<Node> wpNext;

    Node(const std::string& name);  
    ~Node();  
};

#endif // NODE_H
