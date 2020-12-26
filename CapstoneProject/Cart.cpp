#include "Cart.h"

Cart::Cart(Product item, int quantity)
{
	this->item = item;
	this->quantity = quantity;
}

long int Cart::getQuantity() const
{
	return quantity;
}

Product Cart::getItem() const
{
	return item;
}

void Cart::setQuantity(const long int& quantity)
{
	this->quantity = quantity;
}
