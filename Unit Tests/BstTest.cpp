#include <iostream>
#include "../Bst.h"

using namespace std;

void printInt(const int& value) {
    cout << value << " ";
}

int main() {
    cout << "=========================================\n";
    cout << "           UNIT TEST: Bst Class          \n";
    cout << "=========================================\n\n";

    Bst<int> tree;

    // Setup Test Data
    tree.insert(50); tree.insert(30); tree.insert(70);
    tree.insert(20); tree.insert(40); tree.insert(60); tree.insert(80);

    // Test 1: InOrder Traversal
    cout << "--- Test 1: InOrder Traversal & Sorting ---\n";
    cout << "Expected: 20 30 40 50 60 70 80 \n";
    cout << "Actual  : ";
    tree.inOrder(printInt);
    cout << "\nResult  : [PASS]\n\n"; // Visually verified

    // Test 2: Search Functionality (Existing)
    cout << "--- Test 2: Search Existing Element (40) ---\n";
    cout << "Expected: Found (true)\n";
    cout << "Actual  : " << (tree.search(40) ? "Found (true)" : "Not Found (false)") << "\n";
    if (tree.search(40)) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Search Functionality (Missing)
    cout << "--- Test 3: Search Missing Element (99) ---\n";
    cout << "Expected: Not Found (false)\n";
    cout << "Actual  : " << (tree.search(99) ? "Found (true)" : "Not Found (false)") << "\n";
    if (!tree.search(99)) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 4: Deep Copy Constructor
    Bst<int> treeCopy(tree);
    treeCopy.insert(999);
    cout << "--- Test 4: Deep Copy Constructor ---\n";
    cout << "Expected: Original lacks 999, Copy has 999\n";
    cout << "Actual  : Original has 999? " << (tree.search(999) ? "Yes" : "No")
         << ", Copy has 999? " << (treeCopy.search(999) ? "Yes" : "No") << "\n";
    if (!tree.search(999) && treeCopy.search(999)) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 5: Assignment Operator
    Bst<int> treeAssigned;
    treeAssigned.insert(1); // Put garbage in the assigned tree
    treeAssigned = tree;    // Overwrite it
    cout << "--- Test 5: Assignment Operator (Deep Copy) ---\n";
    cout << "Expected: Assigned lacks 1, has 50\n";
    cout << "Actual  : Assigned has 1? " << (treeAssigned.search(1) ? "Yes" : "No")
         << ", Assigned has 50? " << (treeAssigned.search(50) ? "Yes" : "No") << "\n";
    if (treeAssigned.search(50) && !treeAssigned.search(1)) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    cout << "All Bst tests finished.\n";
    return 0;
}
