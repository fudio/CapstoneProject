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
	vector<Cart> listProduct;
	Bill(vector<Cart> lP);
	double getTotal() const;
	time_t getBillCode() const;
	Date getOrderDate() const;
	Date getReceivedDate() const;
};

