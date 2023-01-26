#include <iostream>
using namespace std;

int main()
{
	int t;
	int b;
	cin >> t >> b;
	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		if (a < b)
		{
			cout << a << " ";
		}
	}
	return 0;
}