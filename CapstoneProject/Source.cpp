#include"Product.h"
#include"Cart.h"
#include"Customer.h"

#include<vector>
#include<fstream>
#include<iomanip>
#include<cwchar>
#include<Windows.h>

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
	unsigned int price;
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
void displayProduct(const vector <Product>& l)
{
	if (l.empty())
		cout << "NO PRODUCTS" << endl;
	else
	{
		cout << setfill('*');
		cout << setw(70) << right << "CHOOSE PRODUCT ADD TO CART" << setw(50) << "*" << endl;
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
	}
}
bool addCart(vector <Cart>& t, const vector <Product>& l, const string& proCode, const int& quantity)
{
	for (int i = 0; i < t.size(); i++)
		if (t[i].getProCode() == proCode)
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
void addCartMenu(vector <Cart>& t, const vector <Product>& l, const string& proCode)
{
	bool flag = 1;
	int quantity;
	while (flag)
	{
		cout << "ENTER PRODUCT QUANTITY: ";
		cin >> quantity;
		if (quantity > 0)
		{
			if (!addCart(t, l, proCode, quantity))
			{
				cout << "INVALID PRODUCT CODE!!!" << endl;
			}
			else
			{
				system("cls");
				cout << "THE PRODUCT IS ADDED SUCCESSFULLY" << endl;
				Sleep(750);
			}
			flag = 0;
		}
	}
}
void displayCart(vector<Cart> c)
{

	if (c.empty())
		cout << "CART IS EMPTY" << endl;
	else
	{
		cout << setfill('*');
		cout << setw(69) << right << "PRODUCT LIST IN THE CART" << setw(51) << "*" << endl;
		cout << setfill(' ');
		cout << "\t\t+----------------+---------------------------------------+--------+--------+-----------+" << endl;
		cout << "\t\t|  PRODUCT CODE  |              PRODUCT NAME             |QUANTITY|  UNIT  |   PRICE   |" << endl;
		cout << "\t\t+----------------+---------------------------------------+--------+--------+-----------+" << endl;
		        //   123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		        //   0        1         2         3         4         5         6         7         8         9         10        11        12
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
	}
}
//bool flag = 1;
//string proCode;
//while (flag)
//{
//	system("CLS");
//	display(l);
//	cout << "ENTER PRODUCT CODE ADD TO CARD: ";
//	cin >> proCode;
//	addCartMenu(t, l, proCode);
//}
void mainMenu(vector <Cart>& t, const vector <Product>& l)
{

	swicth(nm) {
	case 1: 
		{
			cout <<"Enter Product "
		}
	}
}

int main()
{
	vector <Cart> t;
	vector <Product> l;
	setFont(24, "Consolas");
	readFile(l);
	mainMenu(t, l);
}