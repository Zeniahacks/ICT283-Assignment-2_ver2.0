#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED


/**
 * @class Time
 * @brief Represents a specific time of day.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * Stores time in hours, minutes, and seconds. Validates input
 * to ensure 24-hour clock rules are followed.
 */
class Time {
public:

    Time();

    Time(int h, int m, int s);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    int toSeconds() const;

    bool operator==(const Time& other) const;
    bool operator<(const Time& other) const;

private:
    int hour;
    int minute;
    int second;

    bool isValidTime(int h, int m, int s) const;
};

#endif // TIME_H_INCLUDED
