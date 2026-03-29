#include "WeatherProcessor.h"
#include "DataLoader.h"
#include "MathUtils.h"
#include <iostream>
#include <fstream>
#include <iomanip>

WeatherProcessor::WeatherProcessor() : db() {}

bool WeatherProcessor::initializeData(const std::string& configFilename) {
    if (DataLoader::loadData(configFilename, db)) {
        return true;
    }
    std::cerr << "Failed to load data." << std::endl;
    return false;
}

std::string WeatherProcessor::getMonthName(int month) const {
    const char* months[] = {"", "January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    if (month >= 1 && month <= 12) return months[month];
    return "Unknown";
}

bool WeatherProcessor::extractMonthData(int month, int year, Vector<float>& speeds, Vector<float>& temps, Vector<float>& solar) const {
    Vector<WeatherRecord*> rawRecords(10);

    if (!db.retrieveMonthData(month, year, rawRecords)) {
        return false;
    }

    for (int i = 0; i < rawRecords.size(); ++i) {
        WeatherRecord* rec = rawRecords[i];

        if (rec->getSpeed() >= 0) {
            speeds.push_back(rec->getSpeed() * 3.6f); // Convert m/s to km/h
        }
        if (rec->getTemp() != -999.0f) {
            temps.push_back(rec->getTemp());
        }
        if (rec->getSolarRad() >= 100.0f) {
            solar.push_back(rec->getSolarRad() * (1.0f / 6.0f) / 1000.0f); // Convert W/m2 to kWh/m2
        }
    }

    return (!speeds.empty() || !temps.empty() || !solar.empty());
}

void WeatherProcessor::displayWindSpeedStats() const {
    int month, year;
    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    Vector<float> speeds(100), temps(100), solar(100);
    bool hasData = extractMonthData(month, year, speeds, temps, solar);

    std::cout << getMonthName(month) << " " << year << ":\n";
    if (!hasData || speeds.empty()) {
        std::cout << "No Data\n";
    } else {
        float avg = MathUtils::calcMean(speeds);
        float stdDev = MathUtils::calcStdDev(speeds, avg);

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Average speed: " << avg << " km/h\n";
        std::cout << "Sample stdev: " << stdDev << "\n";
    }
}

void WeatherProcessor::displayTemperatureStats() const {
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << year << std::endl;

    for (int month = 1; month <= 12; ++month) {
        Vector<float> speeds(100), temps(100), solar(100);
        extractMonthData(month, year, speeds, temps, solar);

        std::cout << getMonthName(month) << ": ";
        if (temps.empty()) {
            std::cout << "No Data\n";
        } else {
            float avg = MathUtils::calcMean(temps);
            float stdDev = MathUtils::calcStdDev(temps, avg);
            std::cout << std::fixed << std::setprecision(1) << "average: " << avg << " degrees C, stdev: " << stdDev << "\n";
        }
    }
}

void WeatherProcessor::displaySpccStats() const {
    int month;
    std::cout << "Enter month (1-12): ";
    std::cin >> month;

    // Requirement: Option 3 applies to the specified month across ALL available years.
    // We don't have a direct way to fetch all years easily, so we will scan a reasonable range.
    Vector<float> allSpeeds(500), allTemps(500), allSolar(500);

    // Assuming a realistic dataset range for demonstration (e.g., 2000-2030)
    for (int year = 2000; year <= 2030; ++year) {
        Vector<float> speeds(100), temps(100), solar(100);
        if (extractMonthData(month, year, speeds, temps, solar)) {
            // Note: sPCC requires paired data. If a specific row is missing one metric,
            // the arrays will misalign. For true sPCC, we must extract them simultaneously.

            // To do this safely, we ask the Database for the raw records of that month/year again.
            Vector<WeatherRecord*> rawRecords(10);
            if (db.retrieveMonthData(month, year, rawRecords)) {
                for (int i = 0; i < rawRecords.size(); ++i) {
                    WeatherRecord* rec = rawRecords[i];
                    // Only push back if ALL THREE are valid to maintain perfect pairing
                    if (rec->getSpeed() >= 0 && rec->getTemp() != -999.0f && rec->getSolarRad() >= 100.0f) {
                        allSpeeds.push_back(rec->getSpeed() * 3.6f);
                        allTemps.push_back(rec->getTemp());
                        allSolar.push_back(rec->getSolarRad() * (1.0f / 6.0f) / 1000.0f);
                    }
                }
            }
        }
    }

    std::cout << "Sample Pearson Correlation Coefficient for " << getMonthName(month) << "\n";
    if (allSpeeds.size() <= 1) {
        std::cout << "Insufficient paired data across years for sPCC calculation.\n";
    } else {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "S_T: " << MathUtils::calcPcc(allSpeeds, allTemps) << "\n";
        std::cout << "S_R: " << MathUtils::calcPcc(allSpeeds, allSolar) << "\n";
        std::cout << "T_R: " << MathUtils::calcPcc(allTemps, allSolar) << "\n";
    }
}

void WeatherProcessor::writeAllStatsToFile() const {
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    std::ofstream outFile("WindTempSolar.csv");
    if (!outFile.is_open()) return;

    outFile << year << "\n";
    bool anyData = false;

    for (int month = 1; month <= 12; ++month) {
        Vector<float> speeds(100), temps(100), solar(100);
        if (extractMonthData(month, year, speeds, temps, solar)) {
            anyData = true;
            outFile << getMonthName(month) << ",";

            // Wind Speed
            if (!speeds.empty()) {
                float avgS = MathUtils::calcMean(speeds);
                float stdDevS = MathUtils::calcStdDev(speeds, avgS);
                float madS = MathUtils::calcMad(speeds, avgS);
                outFile << std::fixed << std::setprecision(1) << avgS << "(" << stdDevS << ", " << madS << "),";
            } else outFile << ",";

            // Temperature
            if (!temps.empty()) {
                float avgT = MathUtils::calcMean(temps);
                float stdDevT = MathUtils::calcStdDev(temps, avgT);
                float madT = MathUtils::calcMad(temps, avgT);
                outFile << std::fixed << std::setprecision(1) << avgT << "(" << stdDevT << ", " << madT << "),";
            } else outFile << ",";

            // Solar Radiation
            if (!solar.empty()) {
                outFile << std::fixed << std::setprecision(1) << MathUtils::calcSum(solar);
            }
            outFile << "\n";
        }
    }

    if (!anyData) outFile << "No Data\n";
    outFile.close();
    std::cout << "Data written to WindTempSolar.csv\n";
}

void WeatherProcessor::showMenu() const {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n=== Weather Data Menu ===\n";
        std::cout << "1. Average Wind Speed & StdDev (Specific Month/Year)\n";
        std::cout << "2. Average Temperature & StdDev (All Months of a Year)\n";
        std::cout << "3. Pearson Correlation Coefficients (Specific Month)\n";
        std::cout << "4. Export Wind, Temp, & Solar Data to CSV (Specific Year)\n";
        std::cout << "5. Exit\n";

        // Debugging option using the BST function pointers!
        std::cout << "6. [Debug] Show Available Years Loaded (BST Check)\n";

        std::cout << "Select an option: ";
        std::cin >> choice;

        std::cout << "\n";
        if (choice == 1) displayWindSpeedStats();
        else if (choice == 2) displayTemperatureStats();
        else if (choice == 3) displaySpccStats();
        else if (choice == 4) writeAllStatsToFile();
        else if (choice == 5) std::cout << "Exiting...\n";
        else if (choice == 6) db.displayAvailableYears();
        else std::cout << "Invalid choice. Try again.\n";
    }
}
