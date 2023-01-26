#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		for (int l = 0;l < i;l++)
		{
			cout << " ";
		}
		for (int k = 0;k < 2*t-2*i-1;k++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}