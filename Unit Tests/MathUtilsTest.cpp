#include <iostream>
#include <iomanip>
#include "../MathUtils.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "        UNIT TEST: MathUtils Class       \n";
    cout << "=========================================\n\n";

    // Setup Test Data
    Vector<float> dataX;
    dataX.push_back(10.0f); dataX.push_back(20.0f); dataX.push_back(30.0f);

    Vector<float> dataY;
    dataY.push_back(15.0f); dataY.push_back(25.0f); dataY.push_back(35.0f);

    cout << "Test Dataset X: {10.0, 20.0, 30.0}\n";
    cout << "Test Dataset Y: {15.0, 25.0, 35.0}\n\n";

    // Test 1: Mean Calculation
    float mean = MathUtils::calcMean(dataX);
    cout << "--- Test 1: Mean Calculation (Dataset X) ---\n";
    cout << "Expected: 20.0\n";
    cout << "Actual  : " << fixed << setprecision(1) << mean << "\n";
    if (mean == 20.0f) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 2: Standard Deviation
    float stdDev = MathUtils::calcStdDev(dataX, mean);
    cout << "--- Test 2: Sample Standard Deviation (Dataset X) ---\n";
    cout << "Expected: 10.0\n";
    cout << "Actual  : " << stdDev << "\n";
    if (stdDev == 10.0f) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 3: Mean Absolute Deviation (MAD)
    float mad = MathUtils::calcMad(dataX, mean);
    cout << "--- Test 3: Mean Absolute Deviation (Dataset X) ---\n";
    cout << "Expected: 6.7\n";
    cout << "Actual  : " << mad << "\n";
    if (mad > 6.6f && mad < 6.7f) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    // Test 4: Sample Pearson Correlation Coefficient (sPCC)
    float pcc = MathUtils::calcPcc(dataX, dataY);
    cout << "--- Test 4: Pearson Correlation (Datasets X & Y) ---\n";
    cout << "Expected: 1.00 (Perfect positive correlation)\n";
    cout << setprecision(2);
    cout << "Actual  : " << pcc << "\n";
    if (pcc > 0.99f) cout << "Result  : [PASS]\n\n";
    else cout << "Result  : [FAIL]\n\n";

    cout << "All MathUtils tests finished.\n";
    return 0;
}
