#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int r, c, s;
int A[51][51];
int map[51][51];
int map2[51][51];
int arr[7][4];
bool ck[102];
vector<int> v;
int min_sum = 10000;
void rotation(int r,int c,int s)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j]= map2[i][j];
		}
	}
	if (r - s >= 1 && r + s <= n && c-s>=1 && c+s<=m)
	{
		while (s > 0)
		{
			int i = 1, j = 1;
			while (i<=2*s && j<=2*s)
			{
				if (c - s + i <= c + s && c + s - i >= c - s)
				{
					map[r - s][c - s + i] = map2[r - s][c - s + (i - 1)];
					map[r + s][c + s - i] = map2[r + s][c + s - (i - 1)];
					i++;
				}
				if (r - s + j <= r + s && r + s - j >= r - s)
				{
					map[r - s + j][c + s] = map2[r - s + (j - 1)][c + s];
					map[r + s - j][c - s] = map2[r + s - (j - 1)][c - s];
					j++;
				}
			}
			s--;
		}
	}
}
void sol(int i) {
	if (i == k) {
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				map2[i][j] = A[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			rotation(arr[v[i]][0], arr[v[i]][1], arr[v[i]][2]);
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					map2[i][j] = map[i][j];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j <= m; j++)
			{
				sum += map[i][j];
			}
			min_sum = min(min_sum, sum);
		}
		return;
	}

	for (int j = 1; j <= k; j++) {
		if (!ck[j]) {
			v.push_back(j);
			ck[j] = true;
			sol(i + 1);
			v.pop_back();
			ck[j] = false;
		}
	}
}


int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	sol(0);
	cout << min_sum;
}