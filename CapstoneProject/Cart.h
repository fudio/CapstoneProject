#pragma once
#include"Product.h"

class Cart :public Product
{
	Product item;
	int quantity;
public:
	Cart(Product, int quantity = 0);
	int getQuantity() const;
	void setQuantity(const int&);
};