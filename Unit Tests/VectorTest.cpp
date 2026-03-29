#include <iostream>
#include "../Vector.h"

using namespace std;

int main() {
    cout << "--- Testing Vector Class ---\n";

    // Test 1: Default Constructor
    Vector<int> v1;
    if (v1.size() == 0 && v1.capacity() == 10)
        cout << "[PASS] Default Constructor\n";
    else
        cout << "[FAIL] Default Constructor\n";

    // Test 2: Parameterized Constructor
    Vector<float> v2(100);
    if (v2.size() == 0 && v2.capacity() == 100)
        cout << "[PASS] Parameterized Constructor (Capacity 100)\n";
    else
        cout << "[FAIL] Parameterized Constructor\n";

    // Test 3: Push Back & Dynamic Resizing
    int initialCapacity = v1.capacity();
    for (int i = 0; i < 15; i++) {
        v1.push_back(i);
    }

    if (v1.size() == 15 && v1.capacity() > initialCapacity && v1[14] == 14)
        cout << "[PASS] Push Back & Dynamic Resizing\n";
    else
        cout << "[FAIL] Push Back & Dynamic Resizing\n";

    // Test 4: Deep Copy Constructor
    Vector<int> vCopy(v1);

    if (vCopy.size() == v1.size() && vCopy[0] == v1[0]) {

        vCopy[0] = 999;

        if (v1[0] != 999)
            cout << "[PASS] Copy Constructor (Deep Copy Confirmed)\n";
        else
            cout << "[FAIL] Copy Constructor (Shallow Copy Detected!)\n";
    } else {
        cout << "[FAIL] Copy Constructor\n";
    }

    // Test 5: Out of Bounds Exception
    try {
        v1[100] = 5; // invalid index
        cout << "[FAIL] Out of Bounds Access (Exception not thrown)\n";
    } catch (const std::out_of_range& e) {
        cout << "[PASS] Out of Bounds Access Throws Exception\n";
    }

    cout << "All Vector tests finished.\n";
    return 0;
}
