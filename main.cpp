#include <iostream>
#include "WeatherProcessor.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "   Weather Data Processing Application   \n";
    cout << "=========================================\n\n";

    WeatherProcessor app;

    // Able to read from multiple data files specified in a data/data_source.txt file.
    string configFile = "data/data_source.txt";

    cout << "[INFO] Initializing Database and Loading Files...\n";

    if (app.initializeData(configFile)) {
        cout << "\n[SUCCESS] Data loaded successfully! Launching Menu...\n";

        // Launch the interactive menu loop
        app.showMenu();

    } else {
        // If data_source.txt is missing or empty, the program halts safely.
        cout << "\n[CRITICAL ERROR] Failed to load data. Please ensure '"
             << configFile << "' exists and contains valid CSV filenames.\n";
        cout << "Exiting application...\n";
    }

    return 0;
}
