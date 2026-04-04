#include <iostream>
#include "../Date.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "           UNIT TEST: Date Class         \n";
    cout << "=========================================\n\n";

    // Test 1: Default Constructor
    Date d1;
    cout << "--- Test 1: Default Constructor ---\n";
    cout << "Expected: 1/1/2000\n";
    cout << "Actual  : " << d1.toString() << "\n";
    if (d1.GetDay() == 1 && d1.GetYear() == 2000) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 2: Parameterized Constructor
    Date d2(15, 8, 2014);
    cout << "--- Test 2: Parameterized Constructor ---\n";
    cout << "Expected: 15/8/2014\n";
    cout << "Actual  : " << d2.toString() << "\n";
    if (d2.GetDay() == 15 && d2.GetMonth() == 8) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Operator Overloads (Equality & Chronology)
    Date d3(15, 8, 2014);
    Date d4(16, 8, 2014); // One day later
    cout << "--- Test 3: Operator Overloads (== and <) ---\n";
    cout << "Expected: d2 == d3 is True | d2 < d4 is True\n";
    cout << "Actual  : d2 == d3 is " << (d2 == d3 ? "True" : "False")
         << " | d2 < d4 is " << (d2 < d4 ? "True" : "False") << "\n";
    if ((d2 == d3) && (d2 < d4)) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    cout << "All Date tests finished.\n";
    return 0;
}
