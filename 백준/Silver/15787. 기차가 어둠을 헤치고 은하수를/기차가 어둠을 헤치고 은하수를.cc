#include <iostream>
#include <vector>

using namespace std;

int n, m;
int bit_set;
int arr[100001];
bool check[2000001];
int cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			arr[b] = arr[b] | (1 << c - 1);
		}
		else if (a == 2)
		{
			cin >> c;
			arr[b] = arr[b] & ~(1 << c - 1);
		}
		else if (a == 3)
		{
			arr[b] = arr[b] << 1;
			if (arr[b] & (1 << 20))
			{
				arr[b] = arr[b] ^ (1 << 20);
			}
		}
		else if (a == 4)
		{
			arr[b] = arr[b] >> 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[arr[i]] == false)
		{
			cnt++;
			check[arr[i]] = true;
		}
	}
	cout << cnt;
}