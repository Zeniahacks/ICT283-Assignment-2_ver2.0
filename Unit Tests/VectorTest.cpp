#include <iostream>
#include "../Vector.h"
using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "          UNIT TEST: Vector Class        \n";
    cout << "=========================================\n\n";

    // Test 1: Default Constructor
    Vector<int> v1;
    cout << "--- Test 1: Default Constructor ---\n";
    cout << "Expected: Size = 0, Capacity = 10\n";
    cout << "Actual  : Size = " << v1.size() << ", Capacity = " << v1.capacity() << "\n";
    if (v1.size() == 0 && v1.capacity() == 10) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 2: Parameterized Constructor
    Vector<float> v2(100);
    cout << "--- Test 2: Parameterized Constructor ---\n";
    cout << "Expected: Size = 0, Capacity = 100\n";
    cout << "Actual  : Size = " << v2.size() << ", Capacity = " << v2.capacity() << "\n";
    if (v2.size() == 0 && v2.capacity() == 100) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Push Back & Dynamic Resizing
    int initialCapacity = v1.capacity();
    for (int i = 0; i < 15; i++) {
        v1.push_back(i);
    }
    cout << "--- Test 3: Push Back & Dynamic Resizing (Adding 15 items) ---\n";
    cout << "Expected: Size = 15, Capacity > 10, Last Element = 14\n";
    cout << "Actual  : Size = " << v1.size() << ", Capacity = " << v1.capacity() << ", Last Element = " << v1[14] << "\n";
    if (v1.size() == 15 && v1.capacity() > initialCapacity && v1[14] == 14) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 4: Deep Copy Constructor
    Vector<int> vCopy(v1);
    vCopy[5] = 999;
    cout << "--- Test 4: Deep Copy Constructor ---\n";
    cout << "Expected: vCopy[5] = 999, Original v1[5] = 5 (Unchanged)\n";
    cout << "Actual  : vCopy[5] = " << vCopy[5] << ", Original v1[5] = " << v1[5] << "\n";
    if (v1[5] != 999) cout << "Result  : [PASS] (Deep Copy Confirmed)\n\n";
    else cout << "Result  : [FAIL] (Shallow Copy Detected!)\n\n";

    // Test 5: Out of Bounds Exception
    cout << "--- Test 5: Out of Bounds Exception Handling ---\n";
    cout << "Expected: Exception caught when accessing v1[999]\n";
    cout << "Actual  : ";
    try {
        v1[999] = 5;
        cout << "No exception thrown!\n";
        cout << "Result  : [FAIL]\n\n";
    } catch (const std::out_of_range& e) {
        cout << "Caught std::out_of_range exception.\n";
        cout << "Result  : [PASS]\n\n";
    }

    cout << "All Vector tests finished.\n";
    return 0;
}
