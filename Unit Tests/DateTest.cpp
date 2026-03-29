#include <iostream>
#include "../Date.h"

using namespace std;

int main() {
    cout << "--- Testing Date Class ---\n";

    // Test 1: Constructors and Getters
    Date d1; // Default
    Date d2(15, 8, 2014); // Parameterized

    if (d1.GetDay() == 1 && d1.GetYear() == 2000) cout << "[PASS] Default Constructor\n";
    else cout << "[FAIL] Default Constructor\n";

    if (d2.GetDay() == 15 && d2.GetMonth() == 8) cout << "[PASS] Parameterized Constructor\n";
    else cout << "[FAIL] Parameterized Constructor\n";

    // Test 2: Operator Overloads (Crucial for Assignment 2 sorting)
    Date d3(15, 8, 2014);
    Date d4(16, 8, 2014); // One day later
    Date d5(15, 9, 2014); // One month later

    if (d2 == d3) cout << "[PASS] Equality Operator (==)\n";
    else cout << "[FAIL] Equality Operator (==)\n";

    if (d2 < d4 && d2 < d5) cout << "[PASS] Less Than Operator (<)\n";
    else cout << "[FAIL] Less Than Operator (<)\n";

    if (d5 > d2) cout << "[PASS] Greater Than Operator (>)\n";
    else cout << "[FAIL] Greater Than Operator (>)\n";

    cout << "All Date tests finished.\n";
    return 0;
}
