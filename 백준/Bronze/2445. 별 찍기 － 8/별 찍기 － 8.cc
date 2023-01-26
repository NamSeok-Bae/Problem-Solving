#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		for (int k = 2 * n - 2-2*i; k > 0; k--)
		{
			cout << " ";
		}
		for (int h = i; h >= 0; h--)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = n-i-1; j > 0; j--)
		{
			cout << "*";
		}
		for (int k = 2*n-2-2*i; k < 2 * n; k++)
		{
			cout << " ";
		}
		for (int h = 1; h <n-i; h++)
		{
			cout << "*";
		}
		cout << endl;
	}
}