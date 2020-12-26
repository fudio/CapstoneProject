#pragma once
#include<string>
#include<iostream>
using namespace std;

class Customer
{
protected:
	string firstName;
	string lastName;
	string sex;
	string phoneNumber;
	string address;
	bool check;
public:
	Customer(string fN = "", string lN = "", string sex = "", string pN = "", string add = "");
	string getFN() const;
	string getLN() const;
	string getSex() const;
	string getPN() const;
	string getAdd() const;
	bool getCheck() const;
	void setFN(string fN);
	void setLN(string lN);
	void setSex(string sex);
	void setPN(string pN);
	void setAdd(string add);
	friend ostream& operator<<(ostream& out, const Customer& c);
};

