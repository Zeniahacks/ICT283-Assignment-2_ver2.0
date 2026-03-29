#include "DataLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

Vector<std::string> DataLoader::splitString(const std::string& str, char delimiter) {
    Vector<std::string> tokens(10); // Start with a small buffer
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool DataLoader::loadData(const std::string& configFilename, Database& db) {
    std::ifstream sourceFile(configFilename);
    if (!sourceFile.is_open()) {
        std::cerr << "Error: Could not open " << configFilename << std::endl;
        return false;
    }

    std::string csvFilename;
    int totalFilesLoaded = 0;

    // Loop to read every file listed inside data_source.txt
    while (std::getline(sourceFile, csvFilename)) {

        // Clean up carriage returns (\r) often found in Windows text files
        if (!csvFilename.empty() && csvFilename[csvFilename.length() - 1] == '\r') {
            csvFilename.erase(csvFilename.length() - 1);
        }
        if (csvFilename.empty()) continue;

        std::string fullPath = "data/" + csvFilename;
        std::ifstream file(fullPath);
        if (!file.is_open()) {
            std::cerr << "Warning: Could not open " << fullPath << ". Skipping..." << std::endl;
            continue;
        }

        std::string line;
        // Read and parse the header line
        if (!std::getline(file, line)) {
            file.close();
            continue;
        }

        Vector<std::string> headers = splitString(line, ',');
        int wastIdx = -1, speedIdx = -1, srIdx = -1, tempIdx = -1;

        for (int i = 0; i < headers.size(); ++i) {
            if (headers[i] == "WAST") wastIdx = i;
            else if (headers[i] == "S") speedIdx = i;
            else if (headers[i] == "SR") srIdx = i;
            else if (headers[i] == "T") tempIdx = i;
        }

        if (wastIdx == -1) {
            std::cerr << "Warning: WAST column missing in " << csvFilename << ". Skipping..." << std::endl;
            file.close();
            continue;
        }

        int recordsLoaded = 0;

        // Process all data lines
        while (std::getline(file, line)) {
            Vector<std::string> fields = splitString(line, ',');
            if (fields.size() < headers.size()) continue; // Skip malformed rows

            std::string dateTime = fields[wastIdx];
            size_t spacePos = dateTime.find(' ');
            if (spacePos == std::string::npos) continue;

            Vector<std::string> dateParts = splitString(dateTime.substr(0, spacePos), '/');
            Vector<std::string> timeParts = splitString(dateTime.substr(spacePos + 1), ':');

            if (dateParts.size() != 3 || timeParts.size() < 2) continue;

            try {
                int day = std::stoi(dateParts);
                int month = std::stoi(dateParts);
                int year = std::stoi(dateParts);
                int hour = std::stoi(timeParts);
                int minute = std::stoi(timeParts);
                int second = (timeParts.size() >= 3) ? std::stoi(timeParts) : 0;

                float speed = -999.0f, temp = -999.0f, sr = -999.0f;

                if (speedIdx != -1 && !fields[speedIdx].empty()) speed = std::stof(fields[speedIdx]);
                if (tempIdx != -1 && !fields[tempIdx].empty()) temp = std::stof(fields[tempIdx]);
                if (srIdx != -1 && !fields[srIdx].empty()) sr = std::stof(fields[srIdx]);

                // HEAP ALLOCATION: Create a new object on the heap
                WeatherRecord* rec = new WeatherRecord(Date(day, month, year), Time(hour, minute, second), speed, temp, sr);

                // Attempt to insert. If it is a duplicate, Database::insertRecord handles the safe deletion.
                if (db.insertRecord(rec)) {
                    recordsLoaded++;
                }

            } catch (...) {
                continue; // Safely skip any rows with corrupted number data
            }
        }

        file.close();
        totalFilesLoaded++;
        std::cout << "Successfully loaded " << recordsLoaded << " unique records from: " << csvFilename << std::endl;
    }

    sourceFile.close();
    return totalFilesLoaded > 0;
}
