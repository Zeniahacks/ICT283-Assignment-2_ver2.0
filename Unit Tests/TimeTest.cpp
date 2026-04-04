#include <iostream>
#include <iomanip>
#include "../Time.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "           UNIT TEST: Time Class         \n";
    cout << "=========================================\n\n";

    // Test 1: Validation
    Time t1(9, 30, 0);
    cout << "--- Test 1: Valid Time Creation ---\n";
    cout << "Expected: 9:30:0\n";
    cout << "Actual  : " << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << "\n";
    if (t1.getHour() == 9 && t1.getMinute() == 30) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 2: Invalid Time Handling
    Time tInvalid(25, 70, 0);
    cout << "--- Test 2: Invalid Time Handling ---\n";
    cout << "Expected: Fallback to 0:0:0\n";
    cout << "Actual  : " << tInvalid.getHour() << ":" << tInvalid.getMinute() << ":" << tInvalid.getSecond() << "\n";
    if (tInvalid.getHour() == 0 && tInvalid.getMinute() == 0) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Chronological Comparison
    Time t2(9, 30, 0);
    Time t3(10, 0, 0);
    cout << "--- Test 3: Operator Overloads (== and <) ---\n";
    cout << "Expected: t1 == t2 is True | t1 < t3 is True\n";
    cout << "Actual  : t1 == t2 is " << (t1 == t2 ? "True" : "False")
         << " | t1 < t3 is " << (t1 < t3 ? "True" : "False") << "\n";
    if ((t1 == t2) && (t1 < t3)) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    cout << "All Time tests finished.\n";
    return 0;
}
