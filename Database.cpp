#include "Database.h"
#include <iostream>


// --------------------------------------------------------------------------
// FUNCTION POINTER IMPLEMENTATION
// This standalone function matches the typedef void (*TraversalFunction)(const T&);
// defined in the Bst. It is passed into the BST traversals as a callback.
// --------------------------------------------------------------------------
static void printYear(const int& year) {
    std::cout << "- " << year << std::endl;
}

Database::Database() : dataStore(), loadedYears() {}

Database::~Database() {
    // Memory Management: We must iterate through every vector in the map
    // and explicitly delete the heap-allocated pointers to prevent memory leaks.
    for (auto it = dataStore.begin(); it != dataStore.end(); ++it) {
        Vector<WeatherRecord*>& vec = it->second;
        for (int i = 0; i < vec.size(); ++i) {
            delete vec[i];
        }
    }
}

int Database::generateKey(int month, int year) const {
    return (year * 100) + month; // E.g., March 2014 becomes 201403
}

bool Database::isDuplicate(const Vector<WeatherRecord*>& vec, const WeatherRecord* record) const {
    // We iterate backwards because data files are usually chronological.
    // If a duplicate exists, it is highly likely to be at the very end of the vector.
    for (int i = vec.size() - 1; i >= 0; --i) {
        if (*vec[i] == *record) {
            return true;
        }
    }
    return false;
}

bool Database::insertRecord(WeatherRecord* record) {
    if (record == nullptr) return false;

    int month = record->getDate().GetMonth();
    int year = record->getDate().GetYear();
    int key = generateKey(month, year);

    // Duplication Check
    if (isDuplicate(dataStore[key], record)) {
        delete record; // Clean up the heap allocation since we are rejecting it
        return false;
    }

    // Use insert instead of push_back to align with your Vector's explicit sizing method
    int currentIndex = dataStore[key].size();
    dataStore[key].insert(currentIndex, record);

    // Track the unique year in the BST
    if (!loadedYears.search(year)) {
        loadedYears.insert(year);
    }

    return true;
}

bool Database::retrieveMonthData(int month, int year, Vector<WeatherRecord*>& outVector) const {
    int key = generateKey(month, year);

    // Checks if the key exists in the map
    auto it = dataStore.find(key);
    if (it != dataStore.end()) {
        outVector = it->second;
        return !outVector.empty();
    }
    return false;
}

void Database::displayAvailableYears() const {
    std::cout << "Years currently loaded in database:" << std::endl;
    // Passing the function pointer 'printYear' to the BST's inOrder traversal method
    loadedYears.inOrder(printYear);
}
