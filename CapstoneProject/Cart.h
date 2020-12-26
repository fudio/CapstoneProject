#pragma once
#include"Product.h"

class Cart :public Product
{
	Product item;
	long int quantity;
public:
	Cart(Product, int quantity = 0);
	long int getQuantity() const;
	Product getItem() const;
	void setQuantity(const long int&);
};