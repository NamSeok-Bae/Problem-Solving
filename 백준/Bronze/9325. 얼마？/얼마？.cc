#include <iostream>

using namespace std;

int main()
{
	int n;
	int s;
	int o;
	int p;
	int q;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		cin >> s;
		cin >> o;
		sum = sum + s;
		for (int j = 0; j < o; j++)
		{
			cin >> p >> q;
			sum = sum + p*q;
		}
		cout << sum << '\n';
	}
}