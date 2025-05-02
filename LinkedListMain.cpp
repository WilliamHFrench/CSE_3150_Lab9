#include <iostream>
#include "LinkedList.h"  

int main() {
    LinkedList llist;

    llist.SERVER_buildCircularLinkedList();
    llist.SERVER_printLinkedList();
    llist.CLIENT_printLinkedList();
    llist.SERVER_deleteCircularLinkedList();
    llist.CLIENT_printLinkedList();

    return 0;
}
