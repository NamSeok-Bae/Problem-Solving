#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int cnt;
vector<int> v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int a, b;
	a = 0;
	b = n - 1;
	while (a < b)
	{
		if ((v[a] + v[b]) == m)
		{
			cnt++;
			a++;
			b--;
		}
		else
		{
			if ((v[a] + v[b]) > m)
			{
				b--;
			}
			else if ((v[a] + v[b]) < m)
			{
				a++;
			}
		}
	}
	cout << cnt;
}