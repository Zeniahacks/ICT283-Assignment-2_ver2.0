#include <iostream>
#include "../Date.h"
#include "../Time.h"
#include "../WeatherRecord.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "      UNIT TEST: WeatherRecord Class     \n";
    cout << "=========================================\n\n";

    Date d1(1, 3, 2014);
    Time t1(9, 0, 0);
    Time t2(9, 10, 0);

    WeatherRecord wr1(d1, t1, 8.0f, 29.5f, 616.0f);
    WeatherRecord wr2(d1, t1, 8.0f, 29.5f, 616.0f); // Duplicate Date/Time
    WeatherRecord wr3(d1, t2, 7.0f, 30.5f, 647.0f); // 10 mins later

    // Test 1: Data Retrieval
    cout << "--- Test 1: Data Getters ---\n";
    cout << "Expected: Speed = 8.0, Temp = 29.5\n";
    cout << "Actual  : Speed = " << wr1.getSpeed() << ", Temp = " << wr1.getTemp() << "\n";
    if (wr1.getSpeed() == 8.0f && wr1.getTemp() == 29.5f) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 2: Duplicate Detection
    cout << "--- Test 2: Exact Duplicate Detection (==) ---\n";
    cout << "Expected: wr1 == wr2 is True\n";
    cout << "Actual  : wr1 == wr2 is " << (wr1 == wr2 ? "True" : "False") << "\n";
    if (wr1 == wr2) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Chronological Sorting
    cout << "--- Test 3: Chronological Sort (<) ---\n";
    cout << "Expected: wr1 < wr3 is True\n";
    cout << "Actual  : wr1 < wr3 is " << (wr1 < wr3 ? "True" : "False") << "\n";
    if (wr1 < wr3) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    cout << "All WeatherRecord tests finished.\n";
    return 0;
}
