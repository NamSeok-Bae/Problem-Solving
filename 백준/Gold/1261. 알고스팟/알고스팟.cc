#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define MAX 1e9

int n, m,map[101][101],dist[101][101];
string s;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

void dijkstra()
{
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    bool visit[101][101] = {false};
    dist[0][0] = 0;
    pq.push({ 0,{0,0} });
    while (!pq.empty())
    {
        int curx = pq.top().second.second;
        int cury = pq.top().second.first;
        int cur_Dist = pq.top().first;
        pq.pop();
        if (visit[cury][curx])
            continue;
        visit[cury][curx] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= m ||  ny >= n || nx < 0 || ny < 0)
                continue;
            if (dist[ny][nx] > cur_Dist + map[ny][nx])
            {
                dist[ny][nx] = cur_Dist + map[ny][nx];
                pq.push({ dist[ny][nx],{ny,nx} });
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j]-'0';
            dist[i][j] = MAX;
        }
    }
    dijkstra();
    cout << dist[n - 1][m - 1];
}
