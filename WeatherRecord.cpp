#include "WeatherRecord.h"


WeatherRecord::WeatherRecord() : d(), t(), speed(-999.0f), temp(-999.0f), solarRad(-999.0f) {}

WeatherRecord::WeatherRecord(const Date& d, const Time& t, float speed, float temp, float solarRad) :
    d(d), t(t), speed(speed), temp(temp), solarRad(solarRad) {}

Date WeatherRecord::getDate() const { return d; }
Time WeatherRecord::getTime() const { return t; }
float WeatherRecord::getSpeed() const { return speed; }
float WeatherRecord::getTemp() const { return temp; }
float WeatherRecord::getSolarRad() const { return solarRad; }

// Checks if this record comes BEFORE the other record chronologically (using time)
bool WeatherRecord::operator<(const WeatherRecord& other) const {
    if (d < other.getDate())
        return true;

    if (d == other.getDate() && t < other.getTime())
        return true;

    return false;
}

// Checks if both records have on the exact same date and time (checking for duplicates)
bool WeatherRecord::operator==(const WeatherRecord& other) const {
    return (d == other.getDate()) && (t == other.getTime());
}



