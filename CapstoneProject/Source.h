#pragma once
#include"Product.h"
#include"Cart.h"
#include"Customer.h"
#include"Bill.h"
#include<vector>
#include<fstream>
#include<iomanip>
#include<cwchar>
#include<Windows.h>

bool check(const vector <Product>& l, const Product& p);	//Ki?m tra trùng l?p mã s?n ph?m

bool readFile(vector <Product>& l);

void setFont(const int& y, const string& front);	//Set font for console

void displayProduct(const vector <Product>& l);

bool addCart(vector <Cart> t, const vector <Product>& l, const string& proCode, const int& quantity);

void addCartMenu(vector <Cart> t, const vector <Product>& l);

bool deleteCartItem(vector<Cart> c, const vector<Product>& l);

bool editCartItem(vector<Cart> c, const vector<Product>& l);

void displayCart(vector<Cart> c);

void inputCustomer(Customer P);

void mainMenu(vector <Cart>& c, const vector <Product>& l);
