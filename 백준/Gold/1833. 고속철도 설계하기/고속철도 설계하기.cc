#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,ans;
int map[201][201];
int parent[201];
vector<pair<int,pair<int,int>>> edge;

int getparent(int parent[] , int x){
    if (parent[x] == x) return x;
    return parent[x] = getparent(parent, parent[x]);
}

//부모 합치기
void unionparent(int parent[], int x, int y) {
    x = getparent(parent, x);
    y = getparent(parent, y);
    if (x < y)parent[y] = x;
    else parent[x] = y;
}

int find(int parent[] , int x, int y) {
    x = getparent(parent, x);
    y = getparent(parent, y);
    if (x == y) return 1;
    else return 0;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(map[i][j] < 0)
            {
                unionparent(parent, i, j);
                ans += -map[i][j];
            }
            edge.push_back({map[i][j],{i,j}});
        }
    }
    sort(edge.begin(),edge.end());
    vector<pair<int,int>> newEdge;
    for(auto a : edge)
    {
        if(!find(parent,a.second.first,a.second.second))
        {
            unionparent(parent, a.second.first, a.second.second);
            newEdge.push_back({a.second.first,a.second.second});
            ans += a.first;
        }
    }
    cout<<ans<<" "<<newEdge.size()<<"\n";
    for(auto a: newEdge)
        cout<<a.first<<" "<<a.second<<"\n";
}
