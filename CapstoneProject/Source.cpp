#include"Source.h"
std::string storeName = "CP";

bool check(const std::vector <Product>& l, const Product& p)		//Kiểm tra trùng lặp mã sản phẩm
{
	for (std::vector <Product>::const_iterator i = l.begin(); i != l.end(); i.operator++())
		if ((*i).getProCode() == p.getProCode())
			return 0;
	return 1;
}
bool readFile(std::vector <Product>& l)
{
	Product p;
	std::ifstream input;
	input.open("Input.txt");
	std::string line;
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
			std::cout << "THE ENTERED HAS A MATCH" << std::endl;
			l.erase(l.begin(), l.end());
			return 0;
		}
	}
	return 1;
}
void setFont(const int& y, const std::string& front)		//Set font for console
{
	std::wstring front_ = std::wstring(front.begin(), front.end());		//Convert string to wstring
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
bool displayProduct(const std::vector <Product>& l)
{
	if (l.empty())
	{
		std::cout << "\t\tPRODUCT LIST IS EMPTY" << std::endl;
		return 0;
	}
	std::cout << std::setw(70) << std::right << "CHOOSE PRODUCT ADD TO CART" << std::setw(50) << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << "\t\t+----------------+------------------------------------------+-----------------+--------+" << std::endl;
	std::cout << "\t\t|  PRODUCT CODE  |               PRODUCT NAME               |  PROCUDE PRICE  |  UNIT  |" << std::endl;
	std::cout << "\t\t+----------------+------------------------------------------+-----------------+--------+" << std::endl;
	for (std::vector <Product>::const_iterator i = l.begin(); i != l.end(); i.operator++())
	{
		std::cout << "\t\t|   " << std::setw(13) << std::left << (*i).getProCode() << "|   " << std::setw(39) << std::left << (*i).getProName() << "|  ";
		std::cout << std::setw(15) << std::left << (*i).getPrice() << "| " << std::setw(7) << std::left << (*i).getUnit() << "|" << std::endl;
	}
	std::cout << "\t\t+----------------+------------------------------------------+-----------------+--------+" << std::endl;
	//   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	//   0        1         2         3         4         5         6         7         8         9         10        11        12
	return 1;
}
bool addCart(std::vector <Cart>& t, const std::vector <Product>& l, const std::string& proCode, const int& quantity)
{
	size_t size = t.size();
	for (int i = 0; i < size; i++)
		if (t[i].getItem().getProCode() == proCode)
		{
			t[i].setQuantity(t[i].getQuantity() + quantity);
			return 1;
		}
	for (std::vector <Product>::const_iterator i = l.begin(); i != l.end(); i.operator++())
		if ((*i).getProCode() == proCode)
		{
			Cart c((*i), quantity);
			t.push_back(c);
			return 1;
		}
	return 0;
}
void addCartMenu(std::vector <Cart>& t, const std::vector <Product>& l)
{
	int quantity;
	std::string proCode;
	std::cout << "\t\tEnter product code add to cart: ";
	fflush(stdin);
	std::cin.ignore();
	getline(std::cin, proCode);
	std::cout << "\t\tEnter product quantity: ";
	std::cin >> quantity;
	if (quantity > 0)
	{
		if (!addCart(t, l, proCode, quantity))
		{
			system("cls");
			std::cout << "\t\tINVALID PRODUCT CODE!!!" << std::endl;
		}
		else
		{
			system("cls");
			std::cout << "\t\tThe PRODUCT IS ADDED SUCCESSFULLY" << std::endl;
			Sleep(750);
		}
	}
	else
	{
		std::cout << "\t\tInvalid quantity" << std::endl;
		Sleep(750);
	}
}
bool deleteCartItem(std::vector<Cart>& c, const std::vector<Product>& l)
{
	std::string proCode;
	std::cout << "\t\tEnter the product code want to delete: ";
	fflush(stdin);
	std::cin.ignore();
	getline(std::cin, proCode);
	size_t size = c.size();
	for (size_t i = 0; i < size; i++)
		if (c[i].getItem().getProCode() == proCode)
		{
			c.erase(c.begin() + i);
			std::cout << "\t\tDELETE SUCCESSFULLY";
			Sleep(750);
			return 1;
		}
	std::cout << "\t\tINVALID PRODUCT CODE";
	Sleep(750);
	return 0;
}
bool editCartItem(std::vector<Cart>& c, const std::vector<Product>& l)
{
	std::string proCode;
	std::cout << "\t\tEnter the product code want to edit: ";
	fflush(stdin);
	std::cin.ignore();
	getline(std::cin, proCode);
	size_t size = c.size();
	for (size_t i = 0; i < size; i++)
		if (c[i].getItem().getProCode() == proCode)
		{
			std::cout << "\t\tEnter new quantity: ";
			long int quantity;
			std::cin >> quantity;
			c[i].setQuantity(quantity);
			return 1;
		}
	std::cout << "\t\tINVALID PRODUCT CODE !!";
	Sleep(750);
	return 0;
}
bool displayCart(std::vector<Cart> c)
{

	if (c.empty())
	{
		std::cout << "\t\tCART IS EMPTY !!" << std::endl;
		return 0;
	}
	else
	{
		std::cout << std::setw(69) << std::right << "PRODUCT LIST IN THE CART" << std::setw(51) << " " << std::endl;
		std::cout << std::setfill(' ');
		std::cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << std::endl;
		std::cout << "\t\t| PRODUCT CODE |              PRODUCT NAME             | QUANTITY |  UNIT  |   PRICE   |" << std::endl;
		std::cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << std::endl;
		for (std::vector <Cart>::const_iterator i = c.begin(); i != c.end(); i.operator++())
		{
			std::cout << "\t\t|   " << std::setw(11) << std::left << (*i).getItem().getProCode() << "|   " << std::setw(36) << std::left << (*i).getItem().getProName() << "| ";
			std::cout << std::setw(9) << std::left << (*i).getQuantity() << "| " << std::setw(7) << std::left << (*i).getItem().getUnit() << "| ";
			std::cout << std::setw(10) << std::left << (*i).getItem().getPrice() << "|" << std::endl;
		}
		std::cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << std::endl;
		//   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		//   0        1         2         3         4         5         6         7         8         9         10        11        12
	}
	return 1;
}
bool addBill(std::vector <Cart>& t, std::vector <Cart>& l, const std::string& proCode)
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
bool addBill_(std::vector <Bill>& b, std::vector <Cart>& l, const std::string& proCode)
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
void addBillMenu(std::vector<Bill>& b, std::vector <Cart>& t, size_t size)
{
	size_t size_ = b.size();
	if (size == size_)
	{
		std::vector<Cart> c;
		std::string proCode;
		std::cout << "\t\tEnter product code add to bill: ";
		fflush(stdin);
		std::cin.ignore();
		getline(std::cin, proCode);
		if (!addBill(c, t, proCode))
		{
			std::cout << "\t\tINVALID PRODUCT CODE !!" << std::endl;
		}
		else
		{
			b.push_back(Bill(c));
			system("cls");
			std::cout << "\t\tThe PRODUCT IS ADDED SUCCESSFULLY" << std::endl;
			Sleep(750);
		}
	}
	else
	{
		std::string proCode;
		std::cout << "\t\tEnter product code add to bill: ";
		fflush(stdin);
		std::cin.ignore();
		getline(std::cin, proCode);
		if (!addBill_(b, t, proCode))
		{
			std::cout << "\t\tINVALID PRODUCT CODE !!" << std::endl;
		}
		else
		{
			system("cls");
			std::cout << "\t\tThe PRODUCT IS ADDED SUCCESSFULLY" << std::endl;
			Sleep(750);
		}
	}
}
bool displayBill(std::vector<Bill> b, Customer c)
{
	if (b.empty())
		return 0;
	system("cls");
	size_t size = b.size();
	std::cout << "\t\tOrder details" << std::endl << std::endl << std::endl;
	std::cout << "\t\tOrder ID: " << b[size - 1].getBillCode() << std::endl;
	std::cout << c;
	std::cout << std::setw(69) << std::right << "Product list in the bill" << std::setw(51) << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << std::endl;
	std::cout << "\t\t| PRODUCT CODE |              PRODUCT NAME             | QUANTITY |  UNIT  |   PRICE   |" << std::endl;
	std::cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << std::endl;
	for (std::vector <Cart>::const_iterator i = (b[size - 1].listProduct).begin(); i != (b[size - 1].listProduct).end(); i.operator++())
	{
		std::cout << "\t\t|   " << std::setw(11) << std::left << (*i).getItem().getProCode() << "|   " << std::setw(36) << std::left << (*i).getItem().getProName() << "| ";
		std::cout << std::setw(9) << std::left << (*i).getQuantity() << "| " << std::setw(7) << std::left << (*i).getItem().getUnit() << "| ";
		std::cout << std::setw(10) << std::left << (*i).getItem().getPrice() << "|" << std::endl;
	}
	std::cout << "\t\t+--------------+---------------------------------------+----------+--------+-----------+" << std::endl;
	//   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	//   0        1         2         3         4         5         6         7         8         9         10        11        12
	std::cout << std::setw(100) << std::right << "Subtotal: " << b[size - 1].getTotal() << std::endl;
	std::cout << std::setw(100) << std::right << "Ship Fee: " << 0.5 << std::endl;
	std::cout << std::setw(100) << std::right << "Order total: " << b[size - 1].getTotal() + 0.5 << std::endl;
	std::cout << "\t\tOrder date: " << b[size - 1].getOrderDate() << std::endl;
	std::cout << "\t\tReceived date: " << b[size - 1].getReceivedDate() << std::endl;
	return 1;
}
void inputCustomer(Customer& P)
{
	std::string s;
	do
	{
		system("CLS");
		std::cout << "\t\tINFORMATION\n" << std::endl;
		std::cout << "\t\t- What your first name?" << std::endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(std::cin, s);
		P.setFN(s);
		std::cout << "\t\t- What your last name?" << std::endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(std::cin, s);
		P.setLN(s);
		std::cout << "\t\t- Male or female?" << std::endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(std::cin, s);
		P.setSex(s);
		std::cout << "\t\t- Your phone number?" << std::endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(std::cin, s);
		P.setPN(s);
		std::cout << "\t\t- What is your address?" << std::endl << "\t\t";
		fflush(stdin);
		//cin.ignore();
		getline(std::cin, s);
		P.setAdd(s);
	} while (!P.getCheck());
}
void output(std::vector<Product> p)
{
	std::ofstream file;
	file.open("product.txt");
	std::ostream_iterator<Product> output_iterator(file, "\n");
	copy(p.begin(), p.end(), output_iterator);
}
template<typename T>
std::string toString(const T& t) 
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}
template<typename T>
T fromString(const std::string& s) {
	std::istringstream stream(s);
	T t;
	stream >> t;
	return t;
}
void output(std::vector<Bill> b)
{
	for (std::vector<Bill>::const_iterator i = b.begin(); i != b.end(); i.operator++())
	{
		time_t bc = (*i).getBillCode();
		std::string file_name = toString<time_t>(bc);
		std::ofstream file("./Bill/" + file_name + ".bin", std::ios::binary | std::ios::app);
		for (std::vector<Cart>::const_iterator j = (*i).listProduct.begin(); j != (*i).listProduct.end(); j.operator++())
		{
			Cart t = *j;
			file.write((char*)&t, sizeof(t));
		}
		file.close();
	}
}
void input(std::vector<Bill>& b)
{
	std::string path = "./Bill";
	std::vector<std::string> lfn;
	for (const auto& entry : fs::directory_iterator(path))
	{
		std::string file_name = toString(entry.path()).substr(9, 10);
		lfn.push_back(file_name);
	}
	for (std::vector<std::string>::const_iterator i = lfn.begin(); i != lfn.end(); i.operator++())
	{
		time_t now = fromString<time_t>(*i);
		Bill t(now);
		std::ifstream file("./Bill/" + *i + ".bin", std::ios::binary);
		Cart tc;
		while (file.read((char*)&tc, sizeof(tc)))
		{
			t.listProduct.push_back(tc);
		}
		b.push_back(t);
	}
}
void mainMenu(std::vector<Bill>& b, std::vector <Cart>& c, std::vector <Product>& l, Customer cus)
{
	input(b);
	system("CLS");
	int key, mm;
	bool flag;
	while (1)
	{
		system("cls");
		std::cout << "\n\t\t";
		std::cout << std::setfill('*');
		std::cout << std::setw(87) << "*" << std::endl;
		std::cout << std::setfill(' ') << "\t\t*" << std::setw(41) << std::right << storeName << " STORE" << std::setw(39) << "*";
		std::cout << "\n\t\t";
		std::cout << std::setfill('*');
		std::cout << std::setw(87) << "*" << std::endl;
		std::cout << std::setfill(' ');
		std::cout << "\t\t*" << std::setw(87) << "*\n";
		std::cout << "\t\t*   Enter (1) to enter " << storeName << " store" << std::setw(58) << "* \n";
		std::cout << "\t\t*" << std::setw(87) << "*\n";
		std::cout << "\t\t*   Enter (2) to view your cart" << std::setw(57) << "*\n";
		std::cout << "\t\t*" << std::setw(87) << "*\n";
		std::cout << "\t\t*   Enter (3) to pay your cart" << std::setw(58) << "*\n";
		std::cout << "\t\t*" << std::setw(87) << "*\n";
		std::cout << "\t\t*   Enter (0) to exit program" << std::setw(59) << "*\n";
		std::cout << "\t\t*" << std::setw(87) << "*\n";
		std::cout << "\t\t";
		std::cout << std::setfill('*');
		std::cout << std::setw(87) << "*" << std::endl;
		std::cout << std::setfill(' ');
		std::cout << "\t\tInput your code: ";
		fflush(stdin);
		std::cin >> key;
		switch (key)
		{
		case 1://them hang vao gio :))))
		{
			flag = 1;
			while (flag)
			{
				system("CLS");
				if (displayProduct(l))
				{
					addCartMenu(c, l);
					std::cout << "\t\tEnter (1) to buy another product or enter (0) to End ";
					std::cout << "\n\t\tInput your code: ";
					std::cin >> mm;
					flag = mm;
				}
			}
			break;
		}
		case 2://edit cart
		{
			if (c.empty())
			{
				std::cout << "\t\tCART IS EMPTY!!!";
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
					std::cout << "\t\tEnter (1) to delete a product in the cart \n\t\tEnter (2) to change quantity a product in the cart\n\t\tEnter (0) to back to Main menu " << std::endl;
					std::cout << "\t\tInput your code: ";
					std::cin >> p;
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
						std::cout << "\t\tEnter (1) to buy another Product or enter (0) to end ";
						std::cout << "\n\t\tInput your code: ";
						std::cin >> mm;
						f = mm;
					}
					else
						f = mm;
				}
				if (b.size() - size)
				{
					system("cls");
					std::cout << "\t\tDo you want to pay?\n\t\tEnter (1) to yes, (0) to no ";
					std::cout << "\n\t\tInput your code: ";
					int k;
					std::cin >> k;
					flag = k;
					if (flag)
					{
						displayBill(b, cus);
						std::cout << std::endl;
						system("pause");
						flag = 0;
					}
					else
						break;
				}
				else
				{
					std::cout << "\n\t\tNO BILL TO PAY!!!";
					Sleep(2000);
					break;
				}
			}
			break;
		}
		case 0:
		{
			output(b);
			output(l);
			exit(0);
		}
		default:
		{
			std::cout << "\t\tINVALID CODE !!  Enter Code again, please!!";
			Sleep(3000);
			break;
		}
		}
	}
}