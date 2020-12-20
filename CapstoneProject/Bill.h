#pragma once
#include"Customer.h"
#include"Date.h"
#include"Cart.h"
#include<vector>

class Bill :public Customer, public Date
{
protected:
	Customer customer;
	vector<Cart> listProduct;
	Date deliveryDate;
	Date receivedDate;
public:
	Bill(Customer cus, vector<Cart> lP);
};

