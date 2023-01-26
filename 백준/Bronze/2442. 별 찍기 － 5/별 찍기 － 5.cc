#include <iostream>

using namespace std;

int main()
{	
	int n;
	int i;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{	
		for (int k = n - i; k > 0; k--)
		{
			cout << " ";
		}
		int a = i + i;
		for (int j = 0; j < (a-1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}