#ifndef WEATHERPROCESSOR_H_INCLUDED
#define WEATHERPROCESSOR_H_INCLUDED

#include "Database.h"
#include <string>

/**
 * @class WeatherProcessor
 * @brief High-level application controller.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * Handles user interaction, coordinates data retrieval from the Database,
 * prepares data for the MathUtils, and formats output according to strict specifications.
 */
class WeatherProcessor {
public:
    /** @brief Default constructor. */
    WeatherProcessor();

    /**
     * @brief Initializes the database by loading data files.
     * @param configFilename The main data text file.
     * @return true if successful, false otherwise.
     */
    bool initializeData(const std::string& configFilename);

    /** @brief Menu Option 1: Displays average wind speed and stdev for a specific month/year. */
    void displayWindSpeedStats() const;

    /** @brief Menu Option 2: Displays average temp and stdev for each month of a specific year. */
    void displayTemperatureStats() const;

    /** @brief Menu Option 3: Displays Sample Pearson Correlation Coefficients (sPCC) for a specific month. */
    void displaySpccStats() const;

    /** @brief Menu Option 4: Writes comprehensive stats (including MAD) to a CSV file. */
    void writeAllStatsToFile() const;

    /** @brief Displays the interactive menu to the user. */
    void showMenu() const;

private:
    Database db; ///< The central data storage unit.

    /**
     * @brief Converts an integer month (1-12) to its string name.
     */
    std::string getMonthName(int month) const;

    /**
     * @brief Extracts validated, purely numerical data for a specific month/year.
     * @details Applies the assignment 1 rules (Wind * 3.6, Solar >= 100 * (1/6) / 1000).
     */
    bool extractMonthData(int month, int year, Vector<float>& speeds, Vector<float>& temps, Vector<float>& solar) const;
};

#endif // WEATHERPROCESSOR_H_INCLUDED
