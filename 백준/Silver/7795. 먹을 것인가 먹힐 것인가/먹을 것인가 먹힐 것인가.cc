#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int a, n;
int b, m;
int cnt;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cnt = 0;
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v1.push_back(a);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b;
			v2.push_back(b);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int left, right;
		for (int i = 0; i < v1.size(); i++)
		{
			for (int j = 0; j < v2.size(); j++)
			{
				if (v1[i] <= v2[j])
					break;
				else
					cnt++;
			}
		}
		cout << cnt << "\n";
	}
}