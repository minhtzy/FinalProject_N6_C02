#include "Date.h"

#include <iostream>

using namespace std;

Date::Date() :day(1),month(1),year(1990)
{
}

Date::Date(int day, int month, int year) 
	: day(day) 
	, month(month)
	, year(year)
{
}

void Date::Input()
{
	cout << "Nhap ngay sinh: ";
	cin >> day;
	cout << "Nhap thang sinh: ";
	cin >> month;
	cout << "Nhap nam sinh: ";
	cin >> year;
}

void Date::Output()
{
	cout << day << "/" << month << "/" << year;
}

int Date::getDay()
{
	return day;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getMonth()
{
	return month;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getYear()
{
	return year;
}

void Date::setYear(int year)
{
	this->year = year;
}

Date::~Date()
{
}
