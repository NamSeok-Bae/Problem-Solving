#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int num1=0;
	for (int i = 1; i <= n; i++)
	{
		num1 = num1 + i;
	}
	cout << num1;
}