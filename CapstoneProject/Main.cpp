#include"Source.h"

int main()
{
	std::vector<Bill> b;
	std::vector <Cart> c;
	std::vector <Product> p;
	Customer cus;
	readFile(p);
	inputCustomer(cus);
	mainMenu(b, c, p, cus);
	return 0;
}