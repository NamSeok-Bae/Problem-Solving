#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a;
			cin >> a;

			int l = 0;
			int r = v.size() - 1;
			int cnt = 0;
			while (l <= r)
			{
				int m = (l + r) / 2;

				if (v[m] == a)
				{
					cnt = 1;
					break;
				}
				if (v[m] > a)
				{
					r = m - 1;
				}
				else
					l = m + 1;
			}
			cout << cnt << "\n";
		}
	}
}