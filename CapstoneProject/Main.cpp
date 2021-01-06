#include"Source.h"

int main()
{
	vector<Bill> b;
	vector <Cart> c;
	vector <Product> p;
	Customer cus;
	readFile(p);
	inputCustomer(cus);
	mainMenu(b, c, p, cus);
	return 0;
}