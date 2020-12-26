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
	vector<Cart> listProduct;
	Date orderDate;
	Date receivedDate;
public:
	Bill(vector<Cart> lP);
	vector<Cart> getCart() const;
	double getTotal() const;
	time_t getBillCode() const;
	Date getOrderDate() const;
	Date getReceivedDate() const;
};

