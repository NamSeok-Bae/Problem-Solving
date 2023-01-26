#include <iostream>

using namespace std;

int a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> a >> b)
	{
		int tmp = a;
		int cmp = 0;
		while (tmp / b != 0)
		{
			a += tmp / b;
			tmp = (tmp % b) + tmp / b;
		}
		cout << a << "\n";
	}
}