#include "Bill.h"
#include<ctime>

Bill::Bill(Customer cus, vector<Cart> lP) :deliveryDate(), receivedDate()
{
	customer = cus;
	listProduct = lP;
	struct tm buf;
	time_t now = time(0);
	localtime_s(&buf, &now);
	deliveryDate.setD(buf.tm_mday);
	deliveryDate.setM(buf.tm_mon);
	deliveryDate.setY(buf.tm_year);
	now += 604800;
	localtime_s(&buf, &now);
	receivedDate.setD(buf.tm_mday);
	receivedDate.setM(buf.tm_mon);
	receivedDate.setY(buf.tm_year);
}
