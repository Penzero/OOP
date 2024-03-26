#pragma once

#include <iostream>

class Date {
private:
    int year;
    int month;
    int day;

    bool isValidDate(int y, int m, int d) {
        if (y < 0) return false;
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31) return false;
        return true;
    }

public:
    Date() : year(1970), month(1), day(1) {}

    Date(int y, int m, int d) {
        if (!isValidDate(y, m, d)) {
            throw std::invalid_argument("Invalid date");
        }
        year = y;
        month = m;
        day = d;
    }

    int getYear() const { return year; }
    void setYear(int y) {
        if (y < 0) throw std::invalid_argument("Invalid year");
        year = y;
    }

    int getMonth() const { return month; }
    void setMonth(int m) {
        if (m < 1 || m > 12) throw std::invalid_argument("Invalid month");
        month = m;
    }

    int getDay() const { return day; }
    void setDay(int d) {
        if (d < 1 || d > 31) throw std::invalid_argument("Invalid day");
        day = d;
    }

    void print() const {
        std::cout << year << "-" << month << "-" << day << std::endl;
    }

    int differenceInDays(const Date& other) const {
        return abs((year * 365 + month * 30 + day) - (other.year * 365 + other.month * 30 + other.day));
    }
};