#include "Date.h"

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Getters
int Date::GetDay() const { return day; }
int Date::GetMonth() const { return month; }
int Date::GetYear() const { return year; }

// Setters
void Date::SetDay(int d) { day = d; }
void Date::SetMonth(int m) { month = m; }
void Date::SetYear(int y) { year = y; }

std::string Date::toString() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
