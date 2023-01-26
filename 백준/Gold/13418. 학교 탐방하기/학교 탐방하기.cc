#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

typedef pair<long long, long long> p;
typedef pair<long long, p> pp;
int N, M;
priority_queue<pp> pq;
priority_queue <pp, vector<pp>, greater<pp>> ppqq;
long long tree[1001];
long long ans;

long long find(int v)
{
    if (tree[v] == v)
    {
        return v;
    }
    return tree[v] = find(tree[v]);
}
void Union(int v1, int v2, int c)
{
    long long a = find(v1);
    long long b = find(v2);
    if (a != b)
    {
        tree[a] = b;
        if (c == 0)
        {
            ans++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    ans = 0;
    for (int i = 0; i <= N; i++)
    {
        tree[i] = i;
    }
    for (int i = 0; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push(pp(w, p(u, v)));
        ppqq.push(pp(w, p(u, v)));
    }
    while (!pq.empty())
    {
        long long cur = pq.top().first;
        long long v1 = pq.top().second.first;
        long long v2 = pq.top().second.second;
        pq.pop();
        Union(v1, v2, cur);
    }
    long long tmp = ans;
    ans = 0;
    for (int i = 0; i <= N; i++)
    {
        tree[i] = i;
    }
    while (!ppqq.empty())
    {
        long long cur = ppqq.top().first;
        long long v1 = ppqq.top().second.first;
        long long v2 = ppqq.top().second.second;
        ppqq.pop();
        Union(v1, v2, cur);
    }
    cout << abs(tmp - ans) * (tmp + ans);
}