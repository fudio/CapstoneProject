#pragma once
#include<iostream>
#include<string>
//using namespace std;

class Product
{
protected:
	std::string proCode;		//Mã sản phẩm
	std::string proName;		//Tên sản phẩm
	double price;		//Giá
	std::string unit;		//Đơn vị tính của sản phẩm
public:
	Product(std::string proCode = "", std::string proName = "", double price = 0, std::string unit = "");
	std::string getProCode() const;
	std::string getProName() const;
	double getPrice() const;
	std::string getUnit() const;
	void setProCode(const std::string&);
	void setProName(const std::string&);
	void setPrice(const double&);
	void setUnit(const std::string&);
	friend std::ostream& operator<<(std::ostream&, const Product&);
};
