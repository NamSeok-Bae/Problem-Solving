#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
bool check[1000001];

int main()
{
	check[1] = true;
	cin >> m >> n;
	for (int i = 2; i * i <= n;i++)
	{
		if (check[i]) continue;
		for (int j = i * 2;j <= n;j += i)
		{
			check[j] = true;
		}
	}
	for (int i = m;i <= n;i++)
	{
		if (check[i] == false) cout << i << "\n";
	}
}