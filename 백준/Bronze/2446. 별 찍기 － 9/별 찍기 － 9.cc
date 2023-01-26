#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k <i; k++)
		{
			cout << " ";
		}
		for (int j = 2 * n - 2 * i - 1; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i < n; i++)
	{
		for (int k = n - i-1; k > 0; k--)
		{
			cout << " ";
		}
		for (int j = 0; j <= 2 * i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}