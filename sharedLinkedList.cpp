#include "sharedLinkedList.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

    sharedLinkedList::sharedLinkedList() {
    root = make_shared<sharedNode>(names[0]);
    numberOfNodes = names.size();
}

void sharedLinkedList::SHARED_buildCircularLinkedList() {
    shared_ptr<sharedNode> node = root;

    for (int i = 1; i < numberOfNodes; i++) {
        shared_ptr<sharedNode>spNext = make_shared<sharedNode>(names[i]);
        node->spNext = spNext;
        node = spNext;
    }
    // completed circle
    node->spNext = root;
}

void sharedLinkedList::SHARED_deleteCircularLinkedList() {
    shared_ptr<sharedNode> node = root;
    shared_ptr<sharedNode> lag;

    while (node->spNext != root) {
        lag = node;
            node = node->spNext;
            lag->spNext.reset();
    }
}




void sharedLinkedList::SHARED_printLinkedList() {
    shared_ptr<sharedNode> node = root;

    for (int i = 1; i < numberOfNodes; i++) {
        if (auto sharedNode = node) {
            cout << "[" << sharedNode->name << "] : "
                 << "use_count: " << sharedNode.use_count()
                 << " address: " << static_cast<const void*>(sharedNode.get())
                 << " next(from shared ptr): "
                 << sharedNode->spNext.get()
                 << endl;
            node = sharedNode->spNext;
        } else {
            cout << "Yipes! shared_ptr not available" << endl;
        }
    }
}
