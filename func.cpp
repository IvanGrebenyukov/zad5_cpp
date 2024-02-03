#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "func.h"


int countWeeks(const Date& date) {
    struct tm timeInfo = { 0 };
    timeInfo.tm_year = date.year - 1900;
    timeInfo.tm_mon = date.month - 1;
    timeInfo.tm_mday = date.day;
    time_t mytime = mktime(&timeInfo);
    int daysFromStart = timeInfo.tm_yday;
    return (daysFromStart / 7);
}
int countWeeks(int year, int month, int day) {
    Date date = { year, month, day };
    return countWeeks(date);
}
int countWeeks(int month, int day) {
    time_t mytime;
    time(&mytime);
    struct  tm* timeInfo = localtime(&mytime);

    Date date = { timeInfo->tm_year + 1900, month, day };
    return countWeeks(date);
}