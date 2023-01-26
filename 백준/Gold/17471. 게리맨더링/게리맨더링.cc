#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int t;
int map[11][11];
vector<int> num;
vector<int> r_num;
bool check[11][11];
bool chk[11];
int arr[11];
bool adj;
int sum;
int r_sum;
int min_bbagi = 10000;

void adjacency(vector<int> v,bool temp)
{
	queue<int> q;
	bool visit[11] = { 0 };
	q.push(v[0]);
	visit[v[0]] = true;
	int cnt = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 1; i <= t; i++)
		{
			if (map[x][i] == 1 && chk[i]== temp && visit[i]==false)
			{
				visit[i] = true;
				cnt++;
				q.push(i);
			}
		}
	}
	if (v.size() == cnt)
		adj = true;
	else
		adj = false;
	return;
}
void combination(int i, int c,int r) {
	if (c == r) {
		sum = 0;
		r_sum = 0;
		while (!r_num.empty())
		{
			r_num.pop_back();
		}
		for (int i = 1; i <= t; i++)
		{
			if (!chk[i])
				r_num.push_back(i);
		}
		adjacency(num, true);
		if (!adj)
			return;
		else
		{
			for (int i = 0; i < num.size(); i++)
			{
				sum += arr[num[i]];
			}
		}
		adjacency(r_num, false);
		if (!adj)
			return;
		else
		{
			for (int i = 0; i < r_num.size(); i++)
			{
				r_sum += arr[r_num[i]];
			}
		}
		min_bbagi = min(min_bbagi, abs(sum - r_sum));
		return;
	}
	if (i > t)
		return;
	num.push_back(i);
	chk[i] = true;
	combination(i + 1, c + 1, r);
	num.pop_back();
	chk[i] = false;
	combination(i + 1, c, r);
	return;
}

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= t; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int num;
			cin >> num;
			map[i][num] = 1;
			map[num][i] = 1;
		}
	}
	for (int i = 1; i < t; i++)
	{
		combination(1, 0,i);
	}
	if (min_bbagi == 10000)
		cout << -1;
	else
		cout << min_bbagi;
}