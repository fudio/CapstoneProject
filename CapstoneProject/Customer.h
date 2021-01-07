#pragma once
#include<string>
#include<iostream>
//using namespace std;

class Customer
{
protected:
	std::string firstName;
	std::string lastName;
	std::string sex;
	std::string phoneNumber;
	std::string address;
	bool check;
public:
	Customer(std::string fN = "", std::string lN = "", std::string sex = "", std::string pN = "", std::string add = "");
	std::string getFN() const;
	std::string getLN() const;
	std::string getSex() const;
	std::string getPN() const;
	std::string getAdd() const;
	bool getCheck();
	void setFN(std::string fN);
	void setLN(std::string lN);
	void setSex(std::string sex);
	void setPN(std::string pN);
	void setAdd(std::string add);
	friend std::ostream& operator<<(std::ostream& out, const Customer& c);
};

