#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <typename T> const T _pow(const T& x1, size_t n)
{
	return pow(x1, n);
}

template<>
const string _pow(const string& x1, size_t n)
{
	string ss = "";
	for (int i = 0; i < n; i++)
	{
		ss += x1;
	}
	return ss;
}

int main()
{
	cout << _pow(2,5) << endl;
	cout << _pow(2.5f ,5) << endl;
	cout << _pow<string>("String", 5) << endl;

	return 0;
}
