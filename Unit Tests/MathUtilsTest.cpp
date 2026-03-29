#include <iostream>
#include "../MathUtils.h"
#include <cmath>

using namespace std;

// Helper function for safe float comparison
bool isEqual(float a, float b) {
    return fabs(a - b) < 0.0001f;
}

int main() {
    cout << "--- Testing MathUtils Class ---\n";

    Vector<float> dataX(5);
    dataX.push_back(10.0f); dataX.push_back(20.0f); dataX.push_back(30.0f);

    Vector<float> dataY(5);
    dataY.push_back(15.0f); dataY.push_back(25.0f); dataY.push_back(35.0f);

    // Mean Calculation
    float mean = MathUtils::calcMean(dataX);
    if (mean == 20.0f) cout << "[PASS] Mean Calculation\n";
    else cout << "[FAIL] Mean Calculation\n";

    // Standard Deviation Calculation
    float stdDev = MathUtils::calcStdDev(dataX, mean);
    if (stdDev == 10.0f) cout << "[PASS] Standard Deviation\n";
    else cout << "[FAIL] Standard Deviation\n";

    // Mean Absolute Deviation Calculation
    float mad = MathUtils::calcMad(dataX, mean);
    if (mad > 6.6f && mad < 6.7f) cout << "[PASS] Mean Absolute Deviation (MAD)\n"; // Should be 6.666...
    else cout << "[FAIL] Mean Absolute Deviation (MAD)\n";

    // Pearson Correlation Calculation (sPCC)
    float pcc = MathUtils::calcPcc(dataX, dataY);
    if (pcc > 0.99f) cout << "[PASS] Pearson Correlation Coefficient (sPCC)\n"; // Perfect positive correlation
    else cout << "[FAIL] Pearson Correlation Coefficient (sPCC)\n";

    cout << "All MathUtils tests finished.\n";
    return 0;
}
