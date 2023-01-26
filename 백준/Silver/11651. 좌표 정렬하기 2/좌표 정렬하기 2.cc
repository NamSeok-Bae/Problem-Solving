#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0;i < n;i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
}