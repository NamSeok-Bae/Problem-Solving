#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = n - i-1; k > 0; k--)
		{
			cout << " ";
		}
		for (int j = n-i; j <= n; j++)
		{
			cout << "*";
		}cout << endl;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 0; k < i+1; k++)
		{
			cout << " ";
		}
		for (int j = n - i-1; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
}