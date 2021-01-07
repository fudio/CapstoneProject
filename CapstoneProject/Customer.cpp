#include "Customer.h"

Customer::Customer(std::string fN, std::string lN, std::string sex, std::string pN, std::string add)
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


std::string Customer::getFN() const
{
	return firstName;
}

std::string Customer::getLN() const
{
	return lastName;
}

std::string Customer::getSex() const
{
	return sex;
}

std::string Customer::getPN() const
{
	return phoneNumber;
}

std::string Customer::getAdd() const
{
	return address;
}

bool Customer::getCheck()
{

	if (firstName == "" || phoneNumber == "" || address == "")
		check = 0;
	else
		check = 1;
	return check;
}

void Customer::setFN(std::string fN)
{
	if (fN == "")
		check = 0;
	else
		firstName = fN;
}

void Customer::setLN(std::string lN)
{
	lastName = lN;
}

void Customer::setSex(std::string sex)
{
	this->sex = sex;
}

void Customer::setPN(std::string pN)
{
	if (pN == "")
		check = 0;
	else
		phoneNumber = pN;
}

void Customer::setAdd(std::string add)
{
	if (add == "")
		check = 0;
	else
		address = add;
}

std::ostream& operator<<(std::ostream& out, const Customer& c)
{
	out << "\t\tFull name: " << c.firstName + " " + c.lastName << std::endl;
	out << "\t\tPhone number: " << c.phoneNumber << std::endl;
	out << "\t\tAddress: " << c.address << std::endl;
	return out;
}
