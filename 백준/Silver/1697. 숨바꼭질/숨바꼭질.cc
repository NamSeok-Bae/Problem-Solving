#include <iostream>
#include <algorithm>
#include <queue>
//BFS
using namespace std;

queue<pair<int,int>> q;
bool visit[1000001];
vector<int> v;
bool chk = true;
int temp = 0;

void BFS(int start,int k)
{
	q.push(pair<int, int>(temp, start));
	while (!q.empty())
	{
		while (!q.empty())
		{
			int check = q.front().second;
			q.pop();
			if (check == k)
			{
				cout << temp;
				chk = false;
				break;
			}
			if (visit[check] == true)
				continue;
			visit[check] = true;
			if (check - 1 >= 0 && check - 1 <= 100000)
				v.push_back(check - 1);
			if (check + 1 >= 0 && check + 1 <= 100000)
				v.push_back(check + 1);
			if (check * 2 >= 0 && check * 2 <= 100000)
				v.push_back(check * 2);
		}
		if (chk == false)
			break;
		temp += 1;
		for (int i = 0;i < v.size();i++)
		{
			q.push(pair<int, int>(temp, v[i]));
		}
		while (!v.empty())
		{
			v.pop_back();
		}
	}
}
int main()
{
	int N, K;
	cin >> N >>K;
	BFS(N,K);
}