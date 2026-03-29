#include <iostream>
#include "../Bst.h"

using namespace std;

// --------------------------------------------------------------------------
// Callback Function for Traversals
// Matches: typedef void (*TraversalFunction)(const T&);
// --------------------------------------------------------------------------
void printInt(const int& value) {
    cout << value << " ";
}

int main() {
    cout << "--- Testing Generic Bst Class ---\n";

    Bst<int> tree;

    // Test 1: Insertion and Sorting
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "\n[INFO] Testing InOrder Traversal (Should print: 20 30 40 50 60 70 80)\nOutput: ";
    tree.inOrder(printInt);
    cout << "\n";

    // Test 2: Search Functionality
    if (tree.search(40)) cout << "[PASS] Search Found Existing Element (40)\n";
    else cout << "[FAIL] Search Found Existing Element (40)\n";

    if (!tree.search(99)) cout << "[PASS] Search Correctly Rejected Missing Element (99)\n";
    else cout << "[FAIL] Search Correctly Rejected Missing Element (99)\n";

    // Test 3: Deep Copy Constructor
    Bst<int> treeCopy(tree);
    treeCopy.insert(999); // Modify the copy

    if (!tree.search(999) && treeCopy.search(999)) {
        cout << "[PASS] Copy Constructor (Deep Copy Confirmed)\n";
    } else {
        cout << "[FAIL] Copy Constructor (Shallow Copy Detected!)\n";
    }

    // Test 4: Assignment Operator
    Bst<int> treeAssigned;
    treeAssigned.insert(1); // Put garbage in the assigned tree
    treeAssigned = tree;    // Overwrite it

    if (treeAssigned.search(50) && !treeAssigned.search(1)) {
        cout << "[PASS] Assignment Operator (Deep Copy Confirmed)\n";
    } else {
        cout << "[FAIL] Assignment Operator\n";
    }

    cout << "\nAll Bst tests finished.\n";
    return 0;
}
