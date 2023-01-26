#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, ans;
int p[1001];
bool check, check2;
bool union_check;
vector<int> YNY;
vector<pair<int, pair<int, int>>>v;

int Find(int x)
{
	if (x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	if (a != b)
	{
		union_check = false;
		for (int i = 0; i < k; i++)
		{
			if (a == YNY[i])
				union_check = true;
		}
		if (union_check)
			p[b] = a;
		else
			p[a] = b;
	}
}

bool Find_YNY(int x,int y)
{
	check = false;
	check2 = false;
	for (int i = 0; i < k; i++)
	{
		if (x == YNY[i])
			check = true;
		if (y == YNY[i])
			check2 = true;
	}
	if (check == true && check2 == true)
	{
		return false;
	}
	return true;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		YNY.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		int cur_cost = i.first;
		int v1 = i.second.first;
		int v2 = i.second.second;
		if (Find(v1) != Find(v2))
		{
			if (Find_YNY(Find(v1), Find(v2)))
			{
				Union(Find(v1), Find(v2));
				ans += cur_cost;
			}
		}
	}
	cout << ans;
}