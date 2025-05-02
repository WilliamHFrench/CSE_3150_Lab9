#include "LinkedList.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

LinkedList::LinkedList() {
    root = make_shared<Node>(names[0]);
    numberOfNodes = names.size();
}

void LinkedList::SERVER_buildCircularLinkedList() {
    shared_ptr<Node> node = root;

    for (int i = 1; i < numberOfNodes; i++) {
        node->spNext = make_shared<Node>(names[i]);
        node->wpNext = node->spNext;
        node = node->spNext;
    }
    // completed circle
    node->spNext = root;
    node->wpNext = root;
}

void LinkedList::SERVER_deleteCircularLinkedList() {
    shared_ptr<Node> node = root;
    shared_ptr<Node> lag;

    while (node->spNext != root) {
        lag = node;
        node = node->spNext;
        lag->spNext.reset();
    }
}

void LinkedList::SERVER_printLinkedList() {
    shared_ptr<Node> node = root;

    for (int i = 1; i < numberOfNodes; i++) {
        cout << "[" << node->name << "] : "
             << "use_count: " << node.use_count()
             << " address: " << node.get()
             << " next(from shared ptr): "
             << node->spNext.get()
             << endl;
        node = node->spNext;
    }
}
void LinkedList::CLIENT_printLinkedList() {
    weak_ptr<Node> node = root;

    for (int i = 1; i < numberOfNodes; i++) {
        if (auto sharedNode = node.lock()) {
            cout << "[" << sharedNode->name << "] : "
                 << "use_count: " << sharedNode.use_count()
                 << " address: " << static_cast<const void*>(sharedNode.get())
                 << " next(from weak ptr): "
                 << sharedNode->wpNext.lock().get()
                 << endl;
            node = sharedNode->wpNext;
        } else {
            cout << "Yipes! shared_ptr not available" << endl;
        }
    }
}
