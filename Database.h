#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <map>
#include "Vector.h"
#include "WeatherRecord.h"

class Database {

public:
    Database();

    ~Database();

    bool insertRecord(WeatherRecord* record);

    bool retrieveMonthData(int month, int year, Vector<WeatherRecord*>& outVector) const;

    void displayAvailableYears() const;

private:
    std::map<int, Vector<WeatherRecord*>> dataStore;

    int generateKey(int month, int year) const;

    bool isDuplicate(const Vector<WeatherRecord*>& vec, const WeatherRecord* record) const;
};

#endif // DATABASE_H_INCLUDED
