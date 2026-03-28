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

    WeatherRecord();

    WeatherRecord(const Date& d, const Time& t, float speed, float temp, float solarRad);

    Date getDate() const;
    Time getTime() const;
    float getSpeed() const;
    float getTemp() const;
    float getSolarRad() const;

    bool operator<(const WeatherRecord& other) const;

    bool operator==(const WeatherRecord& other) const;

private:
    Date d;
    Time t;
    float speed;
    float temp;
    float solarRad;
};


#endif // WEATHERRECORD_H_INCLUDED
