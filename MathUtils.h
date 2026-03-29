#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "Vector.h"

/**
 * @class MathUtils
 * @brief Utility class for pure statistical calculations.
 * @author Elson Ang
 * @date 2026
 * * @details Highly cohesive and decoupled math library. It processes generic
 * float vectors and is completely unaware of weather-specific data types.
 */
class MathUtils {
public:
    /**
     * @brief Calculates the arithmetic mean.
     * @param data Vector of floating point numbers.
     * @return float The mean, or 0.0f if empty.
     */
    static float calcMean(const Vector<float>& data);

    /**
     * @brief Calculates the sample standard deviation.
     * @param data Vector of floating point numbers.
     * @param mean The pre-calculated mean of the data.
     * @return float The standard deviation, or 0.0f if size < 2.
     */
    static float calcStdDev(const Vector<float>& data, float mean);

    /**
     * @brief Calculates the Mean Absolute Deviation (MAD).
     * @param data Vector of floating point numbers.
     * @param mean The pre-calculated mean of the data.
     * @return float The MAD, or 0.0f if empty.
     */
    static float calcMad(const Vector<float>& data, float mean);

    /**
     * @brief Calculates the Sample Pearson Correlation Coefficient (sPCC).
     * @param x First dataset vector.
     * @param y Second dataset vector.
     * @return float The sPCC value between -1.0 and 1.0, or 0.0f if invalid.
     */
    static float calcPcc(const Vector<float>& x, const Vector<float>& y);

    /**
     * @brief Calculates the sum of all elements.
     * @param data Vector of floating point numbers.
     * @return float The sum.
     */
    static float calcSum(const Vector<float>& data);
};

#endif // MATHUTILS_H
