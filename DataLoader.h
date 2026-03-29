#ifndef DATALOADER_H
#define DATALOADER_H

#include "Vector.h"
#include "Database.h"
#include <string>

/**
 * @class DataLoader
 * @brief Responsible for parsing CSV files and creating WeatherRecord objects.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * Pure low-level I/O class. It dynamically allocates memory for new records
 * and passes the pointers to the Database for storage.
 */
class DataLoader {
public:
    /**
     * @brief Reads data_source.txt and parses the target CSV files.
     * @param configFilename The name of the text file containing the list of CSVs.
     * @param db The Database wrapper to populate.
     * @return true if at least one file loaded successfully, false otherwise.
     */
    static bool loadData(const std::string& configFilename, Database& db);

private:
    /**
     * @brief Helper function to split a string by a delimiter.
     */
    static Vector<std::string> splitString(const std::string& str, char delimiter);
};

#endif // DATALOADER_H
