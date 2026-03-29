#include "Time.h"

Time::Time() : hour(0), minute(0), second(0) {}

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {
    if (!isValidTime(h, m, s)) {
        hour = minute = second = 0;
    }
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

bool Time::setTime(int h, int m, int s) {
    if (isValidTime(h, m, s)) {
        hour = h;
        minute = m;
        second = s;
        return true;
    }

    return false;
}

int Time::toSeconds() const {
    return (hour * 3600) + (minute * 60) + second;
}

bool Time::operator==(const Time& other) const {
    return toSeconds() == other.toSeconds();
}

bool Time::operator<(const Time& other) const {
    return toSeconds() < other.toSeconds();
}

bool Time::isValidTime(int h, int m, int s) const {
    return
    (h >= 0 && h < 24) &&
    (m >= 0 && m < 60) &&
    (s >= 0 && s < 60);
}

