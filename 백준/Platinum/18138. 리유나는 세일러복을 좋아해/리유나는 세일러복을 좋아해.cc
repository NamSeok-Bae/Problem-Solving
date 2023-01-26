#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int T_width[201]; // 티셔츠 너비
int S_width[201]; //세일러 카라 너비
vector<int> v[201];
bool visit[201];
int T_S[201];

bool cmp1(int a, int b)
{
	double x = a * 0.5;
	double y = a * 0.75;
	if (b >= x && b <= y)
		return true;
	return false;
}
bool cmp2(int a, int b)
{
	double x = a;
	double y = a * 1.25;
	if (b >= x && b <= y)
		return true;
	return false;
}

bool dfs(int cur_T)
{
	if (visit[cur_T])
		return false;
	visit[cur_T] = true;

	for (int i = 0; i < v[cur_T].size(); i++)
	{
		int nxt_T = v[cur_T][i];
		if (T_S[nxt_T] == 0 || dfs(T_S[nxt_T]))
		{
			T_S[nxt_T] = cur_T;
			return true;
		}
	}
	return false;
}

int bin_matching()
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visit, false, sizeof(visit));
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> T_width[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> S_width[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cmp1(T_width[i], S_width[j]) || cmp2(T_width[i], S_width[j]))
			{
				v[i].push_back(j);
			}
		}
	}
	
	cout << bin_matching();
}