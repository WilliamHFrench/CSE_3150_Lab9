#ifndef SHAREDNODE_H
#define SHAREDNODE_H

#include <string>
#include <memory>

class sharedNode {
public:
    std::string name;
    std::shared_ptr<sharedNode> spNext;  // weak_ptr to avoid circular references

    sharedNode(const std::string& name);  // Constructor declaration
    ~sharedNode();  // Destructor declaration 
};

#endif // SHAREDNODE_H
