#include <iostream>
#include "../Date.h"
#include "../Time.h"
#include "../WeatherRecord.h"

using namespace std;

int main() {
    cout << "--- Testing WeatherRecord Class ---\n";

    Date d1(1, 3, 2014);
    Time t1(9, 0, 0);
    Time t2(9, 10, 0);

    WeatherRecord wr1(d1, t1, 8.0f, 29.5f, 616.0f);
    WeatherRecord wr2(d1, t1, 8.0f, 29.5f, 616.0f); // Duplicate Date/Time
    WeatherRecord wr3(d1, t2, 7.0f, 30.5f, 647.0f); // 10 mins later

    // Test 1: Data Retrieval
    if (wr1.getSpeed() == 8.0f && wr1.getTemp() == 29.5f) cout << "[PASS] Data Getters\n";
    else cout << "[FAIL] Data Getters\n";

    // Test 2: Duplicate Detection (Crucial for DB insertion)
    if (wr1 == wr2) cout << "[PASS] Exact Duplicate Detection (==)\n";
    else cout << "[FAIL] Exact Duplicate Detection (==)\n";

    // Test 3: Chronological Sorting
    if (wr1 < wr3) cout << "[PASS] Chronological Sort (<)\n";
    else cout << "[FAIL] Chronological Sort (<)\n";

    cout << "All WeatherRecord tests finished.\n";
    return 0;
}
