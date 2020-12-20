#include "Customer.h"

Customer::Customer(string fN, string lN, string sex, string pN, string add)
{
	if (fN == "" || pN == "" || add == "")
		check = 0;
	else
	{
		check = 1;
		firstName = fN;
		lastName = lN;
		this->sex = sex;
		phoneNumber = pN;
		address = add;
	}
}


string Customer::getFN() const
{
	return firstName;
}

string Customer::getLN() const
{
	return lastName;
}

string Customer::getSex() const
{
	return sex;
}

string Customer::getPN() const
{
	return phoneNumber;
}

string Customer::getAdd() const
{
	return address;
}

bool Customer::getCheck() const
{
	return check;
}

void Customer::setFN(string fN)
{
	if (fN == "")
		check = 0;
	else
		firstName = fN;
}

void Customer::setLN(string lN)
{
	lastName = lN;
}

void Customer::setSex(string sex)
{
	this->sex = sex;
}

void Customer::setPN(string pN)
{
	if (pN == "")
		check = 0;
	else
		phoneNumber = pN;
}

void Customer::setAdd(string add)
{
	if (add == "")
		check = 0;
	else
		address = add;
}
