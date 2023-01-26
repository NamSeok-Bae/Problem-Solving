#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n,x;
int cnt;
int a, b;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cin >> x;
	a = 0;
	b = n - 1;
	while (a < b)
	{
		if ((v[a] + v[b]) == x)
		{
			cnt++;
			a++;
			b--;
		}
		else
		{
			if ((v[a] + v[b]) > x)
			{
				b--;
			}
			else if ((v[a] + v[b]) < x)
			{
				a++;
			}
		}
	}
	cout << cnt;
}