#include "Date.h"

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::setD(int d)
{
	day = d;
}

void Date::setM(int m)
{
	month = m;
}

void Date::setY(int y)
{
	year = y;
}

ostream& operator<<(ostream& out, const Date& dt)
{
	out << dt.day << "/" << dt.month << "/" << dt.year;
	return out;
}
