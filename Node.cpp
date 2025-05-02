#include "Node.h"

using namespace std;  

Node::Node(const string& name) : name{name} {}

Node::~Node() {
    cout << "Node [" << name << "] destructor" << endl;
}
