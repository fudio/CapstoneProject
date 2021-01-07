#pragma once
#include"Customer.h"
#include"Date.h"
#include"Cart.h"
#include<vector>
#include<ctime>

class Bill :public Date
{
protected:
	time_t billCode;
	Date orderDate;
	Date receivedDate;
public:
	std::vector<Cart> listProduct;
	Bill(std::vector<Cart> lP);
	Bill(time_t billCode);
	double getTotal() const;
	time_t getBillCode() const;
	Date getOrderDate() const;
	Date getReceivedDate() const;
};

