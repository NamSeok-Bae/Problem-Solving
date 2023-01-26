#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		for (int j = 0;j <t-i-1;j++)
		{
			cout << " ";
		}
		for (int k = 0;k <= i;k++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}