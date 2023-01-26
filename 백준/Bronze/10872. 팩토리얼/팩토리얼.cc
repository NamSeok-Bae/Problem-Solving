#include <iostream>

using namespace std;

int fac(int n)
{
	int b = 1;
	if (n == 1)
		return n;

	for (int i = 1;i <= n;i++)
	{
		b *= i;
	}
	return b;
}

int main()
{	
	int a;
	cin >> a;
	cout<<fac(a);
	return 0;
}