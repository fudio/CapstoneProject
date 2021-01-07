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
#include<sstream>
#include<filesystem>


namespace fs = std::filesystem;

bool check(const std::vector <Product>& l, const Product& p);	//Ki?m tra trùng l?p mã s?n ph?m

bool readFile(std::vector <Product>& l);

void setFont(const int& y, const std::string& front);	//Set font for console

bool displayProduct(const std::vector <Product>& l);

bool addCart(std::vector <Cart>& t, const std::vector <Product>& l, const std::string& proCode, const int& quantity);

void addCartMenu(std::vector <Cart>& t, const std::vector <Product>& l);

bool deleteCartItem(std::vector<Cart>& c, const std::vector<Product>& l);

bool editCartItem(std::vector<Cart>& c, const std::vector<Product>& l);

bool editCartItem(std::vector<Cart>& c, const std::vector<Product>& l);

bool displayCart(std::vector<Cart> c);

bool addBill(std::vector <Cart>& t, std::vector <Cart>& l, const std::string& proCode);

bool addBill_(std::vector <Cart>& t, std::vector <Cart>& l, const std::string& proCode);

void addBillMenu(std::vector<Bill>& b, std::vector <Cart>& t, size_t size);

bool displayBill(std::vector<Bill> b, Customer c);

void inputCustomer(Customer& P);

void output(std::vector<Product> p);

template<typename T>
std::string toString(const T& t);

template<typename T>
T fromString(const std::string& s);

void output(std::vector<Bill> b);

void input(std::vector<Bill>& b);

void mainMenu(std::vector<Bill>& b, std::vector <Cart>& c, std::vector <Product>& l, Customer cus);