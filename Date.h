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

    Date(int d, int m, int y);

    int GetDay() const;

    int GetMonth() const;

    int GetYear() const;


    void SetDay(int d);

    void SetMonth(int m);

    void SetYear (int y);


};


#endif // DATE_H_INCLUDED
