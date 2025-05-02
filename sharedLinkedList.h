#ifndef SHAREDLINKEDLIST_H
#define SHAREDLINKEDLIST_H

#include <iostream>
#include <memory>
#include <vector>
#include "sharedNode.h"  

class sharedLinkedList {
public:
    int numberOfNodes;
    std::shared_ptr<sharedNode> root;
    std::vector<std::string> names = { "zero", "one", "two", "three", "four", "five" };

    sharedLinkedList();  // Constructor declaration

    void SHARED_buildCircularLinkedList();  // Function to build the circular linked list
    void SHARED_deleteCircularLinkedList(); // Function to delete nodes except root
    void SHARED_printLinkedList();  // Print the linked list (for weak_ptr)
};

#endif 
