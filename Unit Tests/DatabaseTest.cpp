#include <iostream>
#include "../Date.h"
#include "../Time.h"
#include "../WeatherRecord.h"
#include "../Database.h"

using namespace std;

int main() {
    cout << "--- Testing Database Class ---\n";
    Database db;

    // Test 1: Memory Management & Insertion
    // We allocate on the heap using 'new'. The Database destructor will clean this up later.
    WeatherRecord* rec1 = new WeatherRecord(Date(1, 3, 2014), Time(9, 0, 0), 8.0f, 29.5f, 616.0f);
    WeatherRecord* rec2 = new WeatherRecord(Date(1, 3, 2014), Time(9, 10, 0), 7.0f, 30.5f, 647.0f);

    if (db.insertRecord(rec1) && db.insertRecord(rec2)) {
        cout << "[PASS] Heap Pointer Insertion\n";
    } else {
        cout << "[FAIL] Heap Pointer Insertion\n";
    }

    // Test 2: Duplicate Rejection
    // Creating a record with the exact same Date and Time as rec1
    WeatherRecord* duplicateRec = new WeatherRecord(Date(1, 3, 2014), Time(9, 0, 0), 9.0f, 30.0f, 600.0f);

    if (!db.insertRecord(duplicateRec)) {
        cout << "[PASS] Duplicate Rejection & Memory Cleanup\n";
    } else {
        cout << "[FAIL] Duplicate Rejection\n";
    }

    // Test 3: Data Retrieval
    Vector<WeatherRecord*> retrievedData(10);
    if (db.retrieveMonthData(3, 2014, retrievedData) && retrievedData.size() == 2) {
        cout << "[PASS] Retrieve Month Data via Map Key\n";
    } else {
        cout << "[FAIL] Retrieve Month Data via Map Key\n";
    }

    // Test 4: BST Function Pointers
    cout << "\n[INFO] Testing BST Function Pointers. Expecting to print '2014':\n";
    db.displayAvailableYears();

    cout << "\nAll Database tests finished.\n";
    return 0;
}
