#include <iostream>
#include "sharedLinkedList.h"  

int main() {
    sharedLinkedList llist;

    llist.SHARED_buildCircularLinkedList();
    llist.SHARED_printLinkedList();
    llist.SHARED_deleteCircularLinkedList();
    llist.SHARED_printLinkedList();

    return 0;
}
