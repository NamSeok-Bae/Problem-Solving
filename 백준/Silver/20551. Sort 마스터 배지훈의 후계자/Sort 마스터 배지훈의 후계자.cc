#include <iostream>
#include <vector>
#include <cstring>
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
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;

		int left = 0;
		int right = v.size() - 1;
		bool flag = false;
		while (left < right)
		{
			int mid = (left + right) / 2;

			if (v[mid] == a)
				flag = true;

			if (v[mid] >= a)
			{
				right = mid;
			}
			else
				left = mid + 1;
		}
		if (v[right] == a)
			flag = true;
		if (flag)
			cout << right << "\n";
		else
			cout << -1 << "\n";
	}
}