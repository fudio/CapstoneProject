#include "Product.h"   

Product::Product(string proCode, string proName, double price, string unit)
{
	this->proCode = proCode;
	this->proName = proName;
	this->price = price;
	this->unit = unit;
}

string Product::getProCode() const
{
	return proCode;
}

string Product::getProName() const
{
	return proName;
}

double Product::getPrice() const
{
	return price;
}

string Product::getUnit() const
{
	return unit;
}

void Product::setProCode(const string& proCode)
{
	this->proCode = proCode;
}

void Product::setProName(const string& proName)
{
	this->proName = proName;
}

void Product::setPrice(const double& price)
{
	this->price = price;
}

void Product::setUnit(const string& unit)
{
	this->unit = unit;
}

ostream& operator<<(ostream& out, const Product& p)
{
	out << "Product code: " << p.proCode << endl;
	out << "Product name: " << p.proName << endl;
	out << "Product price: " << p.price << endl;
	out << "Unit of product: " << p.unit << endl;
	return out;
}
