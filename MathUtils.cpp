#include "MathUtils.h"
#include <cmath>

float MathUtils::calcMean(const Vector<float>& data) {
    if (data.empty()) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
    return sum / data.size();
}

float MathUtils::calcStdDev(const Vector<float>& data, float mean) {
    if (data.size() <= 1) return 0.0f;

    float sumSq = 0.0f;
    for (int i = 0; i < data.size(); ++i) {
        sumSq += (data[i] - mean) * (data[i] - mean);
    }
    return std::sqrt(sumSq / (data.size() - 1));
}

float MathUtils::calcMad(const Vector<float>& data, float mean) {
    if (data.empty()) return 0.0f;
    float sumAbs = 0.0f;
    for (int i = 0; i < data.size(); ++i) {
        sumAbs += std::abs(data[i] - mean);
    }
    return sumAbs / data.size();
}

float MathUtils::calcPcc(const Vector<float>& x, const Vector<float>& y) {
    // PCC requires paired data arrays of the exact same length
    if (x.size() != y.size() || x.size() <= 1) return 0.0f;

    float meanX = calcMean(x);
    float meanY = calcMean(y);

    float sumProduct = 0.0f;
    float sumSqX = 0.0f;
    float sumSqY = 0.0f;

    for (int i = 0; i < x.size(); ++i) {
        float diffX = x[i] - meanX;
        float diffY = y[i] - meanY;

        sumProduct += diffX * diffY;
        sumSqX += diffX * diffX;
        sumSqY += diffY * diffY;
    }

    if (sumSqX == 0.0f || sumSqY == 0.0f) return 0.0f;
    return sumProduct / std::sqrt(sumSqX * sumSqY);
}

float MathUtils::calcSum(const Vector<float>& data) {
    float sum = 0.0f;
    for (int i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
    return sum;
}
