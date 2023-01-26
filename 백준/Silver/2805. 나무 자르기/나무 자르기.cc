#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int l = 0;
	int r = 1000000000;
	int max_height = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;

		double sum = 0;
		for (auto a : v)
		{
			if (a > mid)
				sum += a - mid;
		}
		if (sum < m)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
			max_height = max(max_height, mid);
		}
	}
	cout << max_height;
}