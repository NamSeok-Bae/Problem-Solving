#include <iostream>
#include <cmath>

using namespace std;

int t,arr[10001];

int main()
{
	cin >> t;
	for (int i = 0; i <= 10000; i++)
		arr[i] = i;

	for (int i = 2; i <= 10000; i++)
	{
		if (arr[i] == 0) continue;

		for (int j = i * 2; j <= 10000; j += i)
			arr[j] = 0;
	}
	while (t--)
	{
		int a; cin >> a;
		int max_num = 0, min_num = 0, gap = 98654321;
		for (int i = a/2; i >= 2; i--)
		{
			if (arr[i] != 0)
			{
				if (arr[a - arr[i]] != 0)
				{
					cout << arr[i] << " " << a - arr[i] << "\n";
					break;
				}
			}
		}
	}
}