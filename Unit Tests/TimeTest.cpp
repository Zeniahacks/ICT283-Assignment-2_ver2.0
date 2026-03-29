#include <iostream>
#include "../Time.h"

using namespace std;

int main() {
    cout << "--- Testing Time Class ---\n";

    // Test 1: Validation
    Time t1(9, 30, 0);
    Time tInvalid(25, 70, 0); // Should reset to 00:00:00

    if (t1.getHour() == 9 && t1.getMinute() == 30) cout << "[PASS] Valid Time Creation\n";
    else cout << "[FAIL] Valid Time Creation\n";

    if (tInvalid.getHour() == 0 && tInvalid.getMinute() == 0) cout << "[PASS] Invalid Time Handling\n";
    else cout << "[FAIL] Invalid Time Handling\n";

    // Test 2: Chronological Comparison
    Time t2(9, 30, 0);
    Time t3(10, 0, 0);

    if (t1 == t2) cout << "[PASS] Equality Operator (==)\n";
    else cout << "[FAIL] Equality Operator (==)\n";

    if (t1 < t3) cout << "[PASS] Less Than Operator (<)\n";
    else cout << "[FAIL] Less Than Operator (<)\n";

    cout << "All Time tests finished.\n";
    return 0;
}
