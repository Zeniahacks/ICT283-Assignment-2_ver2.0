#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>

/**
 * @class Date
 * @brief Represents a calendar date.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * Manages the day, month, and year. Includes operator overloads
 * for easy chronological comparisons, which is necessary for tree and map sorting.
 */

class Date {

    /**
     * @brief Default constructor. Initializes to 1 January 2000.
     */
    Date();

    /**
     * @brief Parameterized constructor.
     * @param d Day of the month (1-31).
     * @param m Month of the year (1-12).
     * @param y Year.
     */
    Date(int d, int m, int y);

    /** @brief Gets the day. @return int Day (1-31). */
    int GetDay() const;

    /** @brief Gets the month. @return int Month (1-12). */
    int GetMonth() const;

    /** @brief Gets the year. @return int Year. */
    int GetYear() const;


    /** @brief Sets the day. @param d Day (1-31). */
    void SetDay(int d);

    /** @brief Sets the month. @param m Month (1-12). */
    void SetMonth(int m);

    /** @brief Sets the year. @param y Year. */
    void SetYear (int y);

    /**
     * @brief Converts date to string format DD/MM/YYYY.
     * @return std::string Formatted date.
     */
    std::string toString() const;

    /** @brief Less-than operator for chronological sorting. */
    bool operator<(const Date& other) const;

    /** @brief Greater-than operator for chronological sorting. */
    bool operator>(const Date& other) const;

    /** @brief Equality operator. */
    bool operator==(const Date& other) const;

private:
    int day;     ///< Day of the month
    int month;   ///< Month of the year
    int year;    ///< Year
};


#endif // DATE_H_INCLUDED
