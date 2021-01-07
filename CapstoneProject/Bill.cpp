#include "Bill.h"

Bill::Bill(vector<Cart> lP) :orderDate(), receivedDate()
{
	listProduct = lP;
	struct tm buf;
	time_t now = time(0);
	billCode = now;
	localtime_s(&buf, &now);
	orderDate.setD(buf.tm_mday);
	orderDate.setM(buf.tm_mon + 1);
	orderDate.setY(buf.tm_year + 1900);
	now += 604800;
	localtime_s(&buf, &now);
	receivedDate.setD(buf.tm_mday);
	receivedDate.setM(buf.tm_mon + 1);
	receivedDate.setY(buf.tm_year + 1900);
}

Bill::Bill()
{
	struct tm buf;
	time_t now = time(0);
	billCode = now;
	localtime_s(&buf, &now);
	orderDate.setD(buf.tm_mday);
	orderDate.setM(buf.tm_mon + 1);
	orderDate.setY(buf.tm_year + 1900);
	now += 604800;
	localtime_s(&buf, &now);
	receivedDate.setD(buf.tm_mday);
	receivedDate.setM(buf.tm_mon + 1);
	receivedDate.setY(buf.tm_year + 1900);
}

double Bill::getTotal() const
{
	double total = 0;
	for (vector <Cart>::const_iterator i = listProduct.begin(); i != listProduct.end(); i.operator++())
		total += (*i).getItem().getPrice() * (*i).getQuantity();
	return total;
}

time_t Bill::getBillCode() const
{
	return billCode;
}

Date Bill::getOrderDate() const
{
	return orderDate;
}

Date Bill::getReceivedDate() const
{
	return receivedDate;
}
