#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("LinkedList tests") {
    LinkedList list;

    SUBCASE("Build and print with SERVER_printLinkedList") {
        list.SERVER_buildCircularLinkedList();

        ostringstream buffer;
        streambuf* oldCoutStreamBuf = cout.rdbuf();
        cout.rdbuf(buffer.rdbuf());

        list.SERVER_printLinkedList();

        cout.rdbuf(oldCoutStreamBuf); // restore original cout

        string output = buffer.str();
        CHECK(output.find("use_count:") != string::npos);
        CHECK(output.find("next(from shared ptr):") != string::npos);
    }

    SUBCASE("Build and print with CLIENT_printLinkedList") {
        list.SERVER_buildCircularLinkedList();

        ostringstream buffer;
        streambuf* oldCoutStreamBuf = cout.rdbuf();
        cout.rdbuf(buffer.rdbuf());

        list.CLIENT_printLinkedList();

        cout.rdbuf(oldCoutStreamBuf); // restore original cout

        string output = buffer.str();
        CHECK(output.find("use_count:") != string::npos);
        CHECK(output.find("next(from weak ptr):") != string::npos);
    }

    SUBCASE("Delete circular linked list") {
        list.SERVER_buildCircularLinkedList();
        list.SERVER_deleteCircularLinkedList();

        // After delete, root's spNext should no longer point to another node
        CHECK(list.root->spNext == nullptr);
    }
}
