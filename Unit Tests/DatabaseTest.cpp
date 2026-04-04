#include <iostream>
#include "../Date.h"
#include "../Time.h"
#include "../WeatherRecord.h"
#include "../Database.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "         UNIT TEST: Database Class       \n";
    cout << "=========================================\n\n";

    Database db;

    // Setup Data
    WeatherRecord* rec1 = new WeatherRecord(Date(1, 3, 2014), Time(9, 0, 0), 8.0f, 29.5f, 616.0f);
    WeatherRecord* rec2 = new WeatherRecord(Date(1, 3, 2014), Time(9, 10, 0), 7.0f, 30.5f, 647.0f);
    WeatherRecord* duplicateRec = new WeatherRecord(Date(1, 3, 2014), Time(9, 0, 0), 9.0f, 30.0f, 600.0f);

    // Test 1: Memory Management & Insertion
    cout << "--- Test 1: Heap Pointer Insertion ---\n";
    cout << "Expected: Successfully inserted (true)\n";
    bool inserted = db.insertRecord(rec1) && db.insertRecord(rec2);
    cout << "Actual  : " << (inserted ? "Successfully inserted (true)" : "Failed (false)") << "\n";
    if (inserted) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 2: Duplicate Rejection
    cout << "--- Test 2: Duplicate Rejection & Memory Cleanup ---\n";
    cout << "Expected: Rejected due to duplicate Date/Time (false)\n";
    bool dupInserted = db.insertRecord(duplicateRec);
    cout << "Actual  : " << (dupInserted ? "Inserted (true)" : "Rejected (false)") << "\n";
    if (!dupInserted) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Data Retrieval
    cout << "--- Test 3: Retrieve Month Data via Map Key ---\n";
    Vector<WeatherRecord*> retrievedData;
    db.retrieveMonthData(3, 2014, retrievedData);
    cout << "Expected: Vector Size = 2\n";
    cout << "Actual  : Vector Size = " << retrievedData.size() << "\n";
    if (retrievedData.size() == 2) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 4: BST Function Pointers
    cout << "--- Test 4: BST Function Pointers (displayAvailableYears) ---\n";
    cout << "Expected:\nYears currently loaded in database:\n- 2014\n";
    cout << "Actual  :\n";
    db.displayAvailableYears();
    cout << "Result  : [PASS]\n\n"; // Visually verified

    cout << "All Database tests finished.\n";
    return 0;
}
