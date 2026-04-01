#ifndef WEATHERRECORD_H_INCLUDED
#define WEATHERRECORD_H_INCLUDED

#include "Date.h"
#include "Time.h"


/**
 * @class WeatherRecord
 * @brief Represents a single line of weather data.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * Stores Date, Time, and meteorological readings. Implements operator
 * overloads to facilitate duplication checks (identifying records with identical Date/Time).
 */
class WeatherRecord {
public:

    /** @brief Default constructor. */
    WeatherRecord();

    /**
     * @brief Parameterized constructor.
     * @param d Date of the record.
     * @param t Time of the record.
     * @param speed Wind speed in km/h.
     * @param temp Ambient temperature in degrees C.
     * @param solarRad Solar radiation in W/m2.
     */
    WeatherRecord(const Date& d, const Time& t, float speed, float temp, float solarRad);

    /** @brief Gets the Date. @return Date object. */
    const Date& getDate() const;
    /** @brief Gets the Time. @return Time object. */
    const Time& getTime() const;
    /** @brief Gets the Wind Speed. @return float wind speed in km/h. */
    float getSpeed() const;
    /** @brief Gets the Ambient Temperature. @return float temperature in degrees C. */
    float getTemp() const;
    /** @brief Gets the Solar Radiation. @return float solar radiation in W/m2. */
    float getSolarRad() const;

    /**
     * @brief Compares two WeatherRecords chronologically.
     * @details Used for sorting records in BSTs or Maps.
     */
    bool operator<(const WeatherRecord& other) const;

    /**
     * @brief Checks if two WeatherRecords occurred at the exact same Date and Time.
     * @details Crucial for duplicate validation.
     */
    bool operator==(const WeatherRecord& other) const;

private:
    Date d;           ///< Date of the record
    Time t;           ///< Time of the record
    float speed;      ///< Wind speed in km/h
    float temp;       ///< Ambient temperature in Celsius
    float solarRad;   ///< Solar radiation in W/m2
};


#endif // WEATHERRECORD_H_INCLUDED
