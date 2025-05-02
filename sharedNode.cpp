#include "sharedNode.h"
#include <iostream>

using namespace std;

// Constructor definition
sharedNode::sharedNode(const string& name) : name{name} {}

sharedNode::~sharedNode() {
    cout << "Node [" << name << "] destructor" << endl;
}
