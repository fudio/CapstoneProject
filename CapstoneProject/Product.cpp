#include "Product.h"   

Product::Product(std::string proCode, std::string proName, double price, std::string unit)
{
	this->proCode = proCode;
	this->proName = proName;
	this->price = price;
	this->unit = unit;
}

std::string Product::getProCode() const
{
	return proCode;
}

std::string Product::getProName() const
{
	return proName;
}

double Product::getPrice() const
{
	return price;
}

std::string Product::getUnit() const
{
	return unit;
}

void Product::setProCode(const std::string& proCode)
{
	this->proCode = proCode;
}

void Product::setProName(const std::string& proName)
{
	this->proName = proName;
}

void Product::setPrice(const double& price)
{
	this->price = price;
}

void Product::setUnit(const std::string& unit)
{
	this->unit = unit;
}

std::ostream& operator<<(std::ostream& out, const Product& p)
{
	out << "Product code: " << p.proCode << std::endl;
	out << "Product name: " << p.proName << std::endl;
	out << "Product price: " << p.price << std::endl;
	out << "Unit of product: " << p.unit << std::endl;
	return out;
}
