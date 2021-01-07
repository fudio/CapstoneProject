#pragma once
#include<iostream>
//using namespace std;

class Date
{
protected:
	int day, month, year;
public:
	Date(int d = 0, int m = 0, int y = 0);
	void setD(int d);
	void setM(int m);
	void setY(int y);
	friend std::ostream& operator<<(std::ostream& out, const Date& dt);
};

