#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>
#include <vector>
#include "Node.h"  

class LinkedList {
public:
    int numberOfNodes;
    std::shared_ptr<Node> root;
    std::vector<std::string> names = { "zero", "one", "two", "three", "four", "five" };

    LinkedList();  // Constructor declaration

    void SERVER_buildCircularLinkedList();  // Function to build the circular linked list
    void SERVER_deleteCircularLinkedList(); // Function to delete nodes except root
    void SERVER_printLinkedList();  // Print the linked list (for shared_ptr)
    void CLIENT_printLinkedList();  // Print the linked list (for weak_ptr)
};

#endif // LINKEDLIST_H
