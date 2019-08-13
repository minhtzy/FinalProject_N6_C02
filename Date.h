#pragma once

class Date
{
public:
	Date();
	Date(int day, int month, int year);
	int getDay();
	void setDay(int day);
	int getMonth();
	void setMonth(int month);
	int getYear();
	void setYear(int year);
	~Date();
protected:
	int day, month, year;

};