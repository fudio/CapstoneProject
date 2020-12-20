#include "Cart.h"

Cart::Cart(Product item, int quantity)
{
	this->item = item;
	this->quantity = quantity;
}

int Cart::getQuantity() const
{
	return quantity;
}

void Cart::setQuantity(const int& quantity)
{
	this->quantity = quantity;
}
