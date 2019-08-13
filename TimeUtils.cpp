#include "TimeUtils.h"

TimeUtils::TimeUtils()
{
}

time_t TimeUtils::getTime(int day, int month, int year)
{
	struct tm when = { 0 };
	when.tm_year = year;
	when.tm_mon = month - 1;
	when.tm_mday = day;

	return mktime(&when);
}

TimeUtils::~TimeUtils()
{
}
