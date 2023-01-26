#include <iostream>

using namespace std;

bool check[1000001];
int prr[1000001];
int p = 1000000;
int main()
{
	check[1] = true;
	check[2] = true;
	for (int i = 2; i * i <= p; i++)
	{
			for (int j = i * 2; j <= p; j += i)
			{
				if (check[j] == false)
				{
					check[j] = true;
				}
			}
	}
	for (int i = 3; i <= p; i++)
	{
		if (check[i] == false)
		{
			prr[i] = i;
		}
	}
	while (1)
	{
		cin.tie(0);
		ios::sync_with_stdio(0);
		int n;
		bool temp = false;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 3; i <= n / 2; i+=2)
		{
			if (check[n - prr[i]] == false)
			{
				cout << n << " = " << i << " + " << n - i << "\n";
				temp = true;
				break;
			}
		}
		if (!temp)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}