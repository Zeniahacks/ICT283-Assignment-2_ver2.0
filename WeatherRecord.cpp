#include "WeatherRecord.h"


WeatherRecord::WeatherRecord() : d(), t(), speed(-999.0f), temp(-999.0f), solarRad(-999.0f) {}

WeatherRecord::WeatherRecord(const Date& input_d, const Time& input_t, float input_speed, float input_temp, float input_solarRad) :
    d(input_d), t(input_t), speed(input_speed), temp(input_temp), solarRad(input_solarRad) {}

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



