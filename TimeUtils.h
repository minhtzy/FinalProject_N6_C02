#pragma once
#include <ctime>

class TimeUtils
{
public:
	TimeUtils();
	time_t getTime(int day, int month, int year);
	~TimeUtils();

private:

};
