#pragma once
#include<iostream>
#include<string>
using namespace std;

class Product
{
protected:
	string proCode;		//Mã sản phẩm
	string proName;		//Tên sản phẩm
	double price;		//Giá
	string unit;		//Đơn vị tính của sản phẩm
public:
	Product(string proCode = "", string proName = "", double price = 0, string unit = "");
	string getProCode() const;
	string getProName() const;
	double getPrice() const;
	string getUnit() const;
	void setProCode(const string&);
	void setProName(const string&);
	void setPrice(const double&);
	void setUnit(const string&);
	friend ostream& operator<<(ostream&, const Product&);
};
