#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
	cin >> n;
	while (n--)
	{
		int start, finish;
		cin >> start >> finish;
		v.push_back({ finish,start });
	}
	sort(v.begin(), v.end());

	int a = 0, b = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second >= b)
		{
			cnt++;
			b = v[i].first;
		}
	}
	cout << cnt;
}