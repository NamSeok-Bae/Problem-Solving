#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<long long> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		long long a;
		cin >> a;

		v.push_back(a);
	}
	
	long long l = 1;
	long long int r = 2147483647;
	long long int max_distance = 0;
	while (l <= r)
	{
		long long int m = (l + r) / 2;

		long long int cnt = 0;
		for (auto a : v)
		{
			if (a >= m)
			{
				cnt += a / m;
			}
		}

		if (cnt < n)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
			max_distance = max(max_distance, m);
		}
	}
	cout << max_distance;
}