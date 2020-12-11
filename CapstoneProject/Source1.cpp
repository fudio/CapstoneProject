#include<iostream>
using namespace std;

template <class T>
bool search(T x, T* a, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return 1;
	return 0;
}

template <class T>
int search2(T x, T* a, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}

template <class T>
void soft(T* a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a[i] > a[j])
			{
				T t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

template <class T>
void print(T* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

int main()
{
	int a[5] = { 1,3,8,6,2 };
	cout << search(2, a, 5);
	cout << search2(2, a, 5);
	cout << endl;
	print(a, 5);
	soft(a, 5);
	cout << endl;
	print(a, 5);
	return 0;
}