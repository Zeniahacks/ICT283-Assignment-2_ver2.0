#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include "Vector.h"
#include "Bst.h"
#include "WeatherRecord.h"

/**
 * @class Database
 * @brief Central storage and retrieval system for weather data.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * This class encapsulates the STL map and the custom BST.
 * - The std::map handles fast retrieval of data by YearMonth.
 * - The Bst maintains a sorted record of available years, utilizing function pointers.
 * It strictly stores pointers to dynamically allocated WeatherRecords and manages their memory.
 */
class Database {
public:
    /** @brief Default Constructor */
    Database();

    /** @brief Destructor. Safely deletes all heap-allocated WeatherRecords to prevent memory leaks. */
    ~Database();

    /**
     * @brief Inserts a dynamically allocated weather record into the database.
     * @param record Pointer to a heap-allocated WeatherRecord.
     * @return true if successful, false if a duplicate was found (in which case the pointer is deleted).
     */
    bool insertRecord(WeatherRecord* record);

    /**
     * @brief Retrieves all weather records for a specific month and year.
     * @param month The month (1-12).
     * @param year The year.
     * @param outVector The Vector to populate with matching record pointers.
     * @return true if data exists, false otherwise.
     */
    bool retrieveMonthData(int month, int year, Vector<WeatherRecord*>& outVector) const;

    /**
     * @brief Prints all years currently loaded in the database.
     * @details Utilizes the BST's inOrder traversal via a function pointer.
     */
    void displayAvailableYears() const;

private:
    /// Maps a YearMonth key (e.g., 201403) to a Vector of dynamically allocated WeatherRecords.
    std::map<int, Vector<WeatherRecord*>> dataStore;

    /// Tracks the unique years loaded into the system. Keeps the tree shallow and perfectly balanced.
    Bst<int> loadedYears;

    /**
     * @brief Helper function to generate a unique integer key for the map.
     * @param month The month (1-12).
     * @param year The year.
     * @return An integer formatted as YYYYMM (e.g., 201403).
     */
    int generateKey(int month, int year) const;

    /**
     * @brief Performs a strict duplication check.
     * @param vec The Vector to check against.
     * @param record The record to validate.
     * @return true if a record with the exact Date and Time already exists.
     */
    bool isDuplicate(const Vector<WeatherRecord*>& vec, const WeatherRecord* record) const;
};

#endif // DATABASE_H
