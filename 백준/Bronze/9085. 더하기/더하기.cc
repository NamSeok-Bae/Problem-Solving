#include <iostream>

using namespace std;

int main()
{
	int t;
	int n;
	int a;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		int sum = 0;
		cin >> n;
		for (int j = 0;j < n;j++)
		{
			cin >> a;
			sum += a;
		}
		cout << sum <<endl;
	}
}