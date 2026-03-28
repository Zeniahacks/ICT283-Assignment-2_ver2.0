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

    /**
     * @brief Default constructor. Initializes to 00:00:00.
     */
    Time();

    /**
     * @brief Parameterized constructor.
     * @param h Hours (0-23).
     * @param m Minutes (0-59).
     * @param s Seconds (0-59).
     */
    Time(int h, int m, int s);

    /** @brief Gets the hour. @return int Hour (0-23). */
    int getHour() const;

    /** @brief Gets the minute. @return int Minute (0-59). */
    int getMinute() const;

    /** @brief Gets the second. @return int Second (0-59). */
    int getSecond() const;

    /**
     * @brief Sets the time with validation.
     * @return true if valid and set, false otherwise.
     */
    bool setTime(int h, int m, int s);

    /**
     * @brief Converts time to total seconds since midnight for easy comparison.
     * @return int Total seconds.
     */
    int toSeconds() const;

    /** @brief Equality operator. */
    bool operator==(const Time& other) const;

    /** @brief Less-than operator for chronological sorting. */
    bool operator<(const Time& other) const;

private:
    int hour;   ///< Hour component (0-23)
    int minute; ///< Minute component (0-59)
    int second; ///< Second component (0-59)

    /**
     * @brief Helper to validate time components.
     */
    bool isValidTime(int h, int m, int s) const;
};

#endif // TIME_H_INCLUDED
