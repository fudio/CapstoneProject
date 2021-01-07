#include"Source.h"
string storeName = "CP";

bool check(const vector <Product>& l, const Product& p)		//Kiểm tra trùng lặp mã sản phẩm
{
	for (vector <Product>::const_iterator i = l.begin(); i != l.end(); i.operator++())
		if ((*i).getProCode() == p.getProCode())
			return 0;
	return 1;
}
bool readFile(vector <Product>& l)
{
	Product p;
	ifstream input;
	input.open("Input.txt");
	string line;
	double price;
	while (getline(input, line))
	{
		p.setProCode(line);
		getline(input, line);
		p.setProName(line);
		input >> price;
		p.setPrice(price);
		getline(input, line);
		getline(input, line);
		p.setUnit(line);
		if (check(l, p))		//Nếu có mã sản phẩm trùng lặp thì dừng cả chương trình
			l.push_back(p);
		else
		{
			cout << "The entered data has a match" << endl;
			l.erase(l.begin(), l.end());
			return 0;
		}
	}
	return 1;
}
void setFont(const int& y, const string& front)		//Set font for console
{
	wstring front_ = wstring(front.begin(), front.end());		//Convert string to wstring
	const wchar_t* _front = front_.c_str();		//Convert wstring to wchar_t
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = y;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, _front);	// Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
bool displayProduct(const vector <Product>& l)
{
	if (l.empty())
	{
		cout << "\t\tNo product" << endl;
		return 0;
	}
	cout << setw(70) << right << "CHOOSE PRODUCT ADD TO CART" << setw(50) << " " << endl;
	cout << setfill(' ');
	cout << "\t\t+----------------+------------------------------------------+-----------------+--------+" << endl;
	cout << "\t\t|  PRODUCT CODE  |               PRODUCT NAME               |  PROCUDE PRICE  |  UNIT  |" << endl;
	cout << "\t\t+----------------+------------------------------------------+-----------------+--------+" << endl;
	for (vector <Product>::const_iterator i = l.begin(); i != l.end(); i.operator++())
	{
		cout << "\t\t|   " << setw(13) << left << (*i).getProCode() << "|   " << setw(39) << left << (*i).getProName() << "|  ";
		cout << setw(15) << left << (*i).getPrice() << "| " << setw(7) << left << (*i).getUnit() << "|" << endl;
	}
	cout << "\t\t+----------------+------------------------------------------+-----------------+--------+" << endl;
	//   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	//   0        1         2         3         4         5         6         7         8         9         10        11        12
	return 1;
}
bool addCart(vector <Cart>& t, const vector <Product>& l, const string& proCode, const int& quantity)
{
	size_t size = t.size();
	for (int i = 0; i < size; i++)
		if (t[i].getItem().getProCode() == proCode)
		{
			t[i].setQuantity(t[i].getQuantity() + quantity);
			return 1;
		}
	for (vector <Product>::const_iterator i = l.begin(); i != l.end(); i.operator++())
		if ((*i).getProCode() == proCode)
		{
			Cart c((*i), quantity);
			t.push_back(c);
			return 1;
		}
	return 0;
}
void addCartMenu(vector <Cart>& t, const vector <Product>& l)
{
	int quantity;
	string proCode;
	cout << "\t\tEnter product code add to cart: ";
	fflush(stdin);
	cin.ignore();
	getline(cin, proCode);
	cout << "\t\tEnter product quantity: ";
	cin >> quantity;
	if (quantity > 0)
	{
		if (!addCart(t, l, proCode, quantity))
		{
			system("cls");
			cout << "\t\tInvalid product code!!!" << endl;
		}
		else
		{
			system("cls");
			cout << "\t\tThe product is added successfully!" << endl;
			Sleep(750);
		}
	}
	else
	{
		cout << "\t\tInvalid quantity";
		Sleep(750);
	}
}
bool deleteCartItem(vector<Cart>& c, const vector<Product>& l)
{
	string proCode;
	cout << "\t\tEnter the product code want to delete: ";
	fflush(stdin);
	cin.ignore();
	getline(cin, proCode);
	size_t size = c.size();
	for (size_t i = 0; i < size; i++)
		if (c[i].getItem().getProCode() == proCode)
		{
			c.erase(c.begin() + i);
			cout << "\t\tDELETE SUCCESSFULLY";
			Sleep(750);
			return 1;
		}
	cout << "\t\tINVALID PRODUCT CODE";
	Sleep(750);
	return 0;
}
bool editCartItem(vector<Cart>& c, const vector<Product>& l)
{
	string proCode;
	cout << "\t\tEnter the product code want to edit: ";
	fflush(stdin);
	cin.ignore();
	getline(cin, proCode);
	size_t size = c.size();
	for (size_t i = 0; i < size; i++)
		if (c[i].getItem().getProCode() == proCode)
		{
			cout << "\t\tEnter new quantity: ";
			long int quantity;
			cin >> quantity;
			c[i].setQuantity(quantity);
			return 1;
		}
	cout << "\t\tINVALID PRODUCT CODE !!";
	Sleep(750);
	return 0;
}
bool displayCart(vector<Cart> c)
{

	if (c.empty())
	{
		cout << "\t\tCART IS EMPTY !!" << endl;
		return 0;
	}
	else
	{
		cout << setw(69) << right << "PRODUCT LIST IN THE CART" << setw(51) << " " << endl;
		cout << setfill(' ');
		cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << endl;
		cout << "\t\t| PRODUCT CODE |              PRODUCT NAME             | QUANTITY |  UNIT  |   PRICE   |" << endl;
		cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << endl;
		for (vector <Cart>::const_iterator i = c.begin(); i != c.end(); i.operator++())
		{
			cout << "\t\t|   " << setw(11) << left << (*i).getItem().getProCode() << "|   " << setw(36) << left << (*i).getItem().getProName() << "| ";
			cout << setw(9) << left << (*i).getQuantity() << "| " << setw(7) << left << (*i).getItem().getUnit() << "| ";
			cout << setw(10) << left << (*i).getItem().getPrice() << "|" << endl;
		}
		cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << endl;
		//   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		//   0        1         2         3         4         5         6         7         8         9         10        11        12
	}
	return 1;
}
bool addBill(vector <Cart>& t, vector <Cart>& l, const string& proCode)
{
	size_t size = l.size();
	for (int i = 0; i < size; i++)
		if ((l[i]).getItem().getProCode() == proCode)
		{
			t.push_back(l[i]);
			l.erase(l.begin() + i);
			return 1;
		}
	//for (vector <Cart>::const_iterator i = l.begin(); i != l.end(); i.operator++())
	//{
	//	if ((*i).getProCode() == proCode)
	//	{
	//		t.push_back(*i);
	//		l.erase(i);
	//		return 1;
	//	}
	//}
	return 0;
}
bool addBill_(vector <Bill>& b, vector <Cart>& l, const string& proCode)
{
	size_t size = l.size();
	for (int i = 0; i < size; i++)
		if ((l[i]).getItem().getProCode() == proCode)
		{
			b.back().listProduct.push_back(l[i]);
			l.erase(l.begin() + i);
			return 1;
		}
	//for (vector <Cart>::const_iterator i = l.begin(); i != l.end(); i.operator++())
	//{
	//	if ((*i).getProCode() == proCode)
	//	{
	//		t.push_back(*i);
	//		l.erase(i);
	//		return 1;
	//	}
	//}
	return 0;
}
void addBillMenu(vector<Bill>& b, vector <Cart>& t, size_t size)
{
	size_t size_ = b.size();
	if (size == size_)
	{
		vector<Cart> c;
		string proCode;
		cout << "\t\tEnter product code add to bill: ";
		fflush(stdin);
		cin.ignore();
		getline(cin, proCode);
		if (!addBill(c, t, proCode))
		{
			cout << "\t\tINVALID PRODUCT CODE !!" << endl;
		}
		else
		{
			b.push_back(Bill(c));
			system("cls");
			cout << "\t\tThe product is added successfully" << endl;
			Sleep(750);
		}
	}
	else
	{
		string proCode;
		cout << "\t\tEnter product code add to bill: ";
		fflush(stdin);
		cin.ignore();
		getline(cin, proCode);
		if (!addBill_(b, t, proCode))
		{
			cout << "\t\tINVALID PRODUCT CODE !!" << endl;
		}
		else
		{
			system("cls");
			cout << "\t\tThe product is added successfully" << endl;
			Sleep(750);
		}
	}
}
bool displayBill(vector<Bill> b, Customer c)
{
	if (b.empty())
		return 0;
	system("cls");
	size_t size = b.size();
	cout << "Order details" << endl << endl << endl;
	cout << "Order ID: " << b[size - 1].getBillCode() << endl;
	cout << c;
	cout << setw(69) << right << "Product list in the bill" << setw(51) << " " << endl;
	cout << setfill(' ');
	cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << endl;
	cout << "\t\t| PRODUCT CODE |              PRODUCT NAME             | QUANTITY |  UNIT  |   PRICE   |" << endl;
	cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << endl;
	for (vector <Cart>::const_iterator i = (b[size - 1].listProduct).begin(); i != (b[size - 1].listProduct).end(); i.operator++())
	{
		cout << "\t\t|   " << setw(11) << left << (*i).getItem().getProCode() << "|   " << setw(36) << left << (*i).getItem().getProName() << "| ";
		cout << setw(9) << left << (*i).getQuantity() << "| " << setw(7) << left << (*i).getItem().getUnit() << "| ";
		cout << setw(10) << left << (*i).getItem().getPrice() << "|" << endl;
	}
	cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << endl;
	//   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	//   0        1         2         3         4         5         6         7         8         9         10        11        12
	cout << setw(100) << right << "Subtotal: " << b[size - 1].getTotal() << endl;
	cout << setw(100) << right << "Ship Fee: " << 0.5 << endl;
	cout << setw(100) << right << "Order total: " << b[size - 1].getTotal() + 0.5 << endl;
	cout << "Order date: " << b[size - 1].getOrderDate() << endl;
	cout << "Received date: " << b[size - 1].getReceivedDate() << endl;
	return 1;
}
void inputCustomer(Customer& P)
{
	string s;
	do
	{
		system("CLS");
		cout << "\t\tINFORMATION\n" << endl;
		cout << "\t\t- What your first name?" << endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(cin, s);
		P.setFN(s);
		cout << "\t\t- What your last name?" << endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(cin, s);
		P.setLN(s);
		cout << "\t\t- Male or female?" << endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(cin, s);
		P.setSex(s);
		cout << "\t\t- Your phone number?" << endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(cin, s);
		P.setPN(s);
		cout << "\t\t- What is your address?" << endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(cin, s);
		P.setAdd(s);
	} while (!P.getCheck());
}
void output(vector<Product> p)
{
	ofstream bill;
	bill.open("product.txt");
	ostream_iterator<Product> output_iterator(bill, "\n");
	copy(p.begin(), p.end(), output_iterator);
}
void mainMenu(vector<Bill>& b, vector <Cart>& c, vector <Product>& l, Customer cus)
{
	system("CLS");
	int key, mm;
	bool flag;
	while (1)
	{
		system("cls");
		cout << "\n\t\t";
		cout << setfill('*');
		cout << setw(87) << "*" << endl;
		cout << setfill(' ') << "\t\t*" << setw(41) << right << storeName << " STORE" << setw(39) << "*";
		cout << "\n\t\t";
		cout << setfill('*');
		cout << setw(87) << "*" << endl;
		cout << setfill(' ');
		cout << "\t\t*" << setw(87) << "*\n";
		cout << "\t\t*   Enter (1) to enter " << storeName << " store" << setw(58) << "* \n";
		cout << "\t\t*" << setw(87) << "*\n";
		cout << "\t\t*   Enter (2) to view your cart" << setw(57) << "*\n";
		cout << "\t\t*" << setw(87) << "*\n";
		cout << "\t\t*   Enter (3) to pay your cart" << setw(58) << "*\n";
		cout << "\t\t*" << setw(87) << "*\n";
		cout << "\t\t*   Enter (0) to exit program" << setw(59) << "*\n";
		cout << "\t\t*" << setw(87) << "*\n";
		cout << "\t\t";
		cout << setfill('*');
		cout << setw(87) << "*" << endl;
		cout << setfill(' ');
		cout << "\t\tInput your code: ";
		fflush(stdin);
		cin >> key;
		switch (key)
		{
		case 1://them hang vao gio :))))
		{
			flag = 1;
			while (flag)
			{
				system("CLS");
				displayProduct(l);
				addCartMenu(c, l);
				cout << "\t\tEnter (1) to buy another Product or Enter (0) to End ";
				cout << "\n\t\tInput your code: ";
				cin >> mm;
				flag = mm;
			}
			break;
		}
		case 2://edit cart
		{
			if (c.empty())
			{
				cout << "\t\tCART IS EMPTY!!!";
				Sleep(2000);
			}
			else
			{
				flag = 1;
				while (flag)
				{
					system("CLS");
					displayCart(c);
					int p;
					cout << "\t\tEnter (1) to delete a product in the cart \n\t\tEnter (2) to change quantity a product in the cart\n\t\tEnter (0) to back to Main menu " << endl;
					cout << "\t\tInput your code: ";
					cin >> p;
					if (p == 1)
						deleteCartItem(c, l);
					else if (p == 2)
						editCartItem(c, l);
					else if (p == 0)
						flag = 0;
				}
			}
			break;
		}
		case 3://Tu gio hang vao bill
		{
			flag = 1;
			while (flag)
			{
				int f = 1;
				size_t size = b.size();
				while (f)
				{
					system("CLS");
					mm = displayCart(c);
					if (mm)
					{
						addBillMenu(b, c, size);
						cout << "\t\tEnter (1) to buy another Product or Enter (0) to End ";
						cout << "\n\t\tInput your code: ";
						cin >> mm;
						f = mm;
					}
					else
						f = mm;
				}
				if (b.size() - size)
				{
					system("cls");
					cout << "\t\tDo you want to pay?\n\t\tEnter (1) to yes, (0) to no ";
					cout << "\n\t\tInput your code: ";
					int k;
					cin >> k;
					flag = k;
					if (flag)
					{
						displayBill(b, cus);
						cout << endl;
						system("pause");
						flag = 0;
					}
					else
						break;
				}
				else
				{
					cout << "\t\tNO BILL TO PAY!!!";
					Sleep(2000);
					break;
				}
			}
			break;
		}
		case 0:
		{
			output(l);
			exit(0);
		}
		default:
		{
			cout << "\t\tINVALID CODE !!  Enter Code again, please!!";
			Sleep(3000);
			break;
		}
		}
	}
}