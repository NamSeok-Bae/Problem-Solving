#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int n;
int visit[10001];

int left_lotation(int num)
{
    if(num >= 1000)
    {
        int temp = num/1000;
        num %= 1000;
        num = num * 10 + temp;
        return num;
    }
    else
        return num * 10;
}
int right_lotation(int num)
{
    int temp = num % 10;
    num /= 10;
    num += temp * 1000;
    return num;
}
string bfs (int cur, int correct)
{
    queue<pair<string,int>> q;
    q.push({"",cur});
    while(!q.empty())
    {
        string cur_ans = q.front().first;
        int cur = q.front().second;
        q.pop();
        if(cur == correct)
            return cur_ans;
        if(visit[cur])
            continue;
        visit[cur] = 1;
        int temp;
        if(cur * 2 > 9999)
        {
            q.push({cur_ans+"D",(cur*2)%10000});
            temp =(cur*2)%10000;
        }
        else
        {
            q.push({cur_ans+"D",cur*2});
            temp = cur*2;
        }
        if(temp == correct)
            return cur_ans +"D";
        if(cur==0)
        {
            q.push({cur_ans+"S",9999});
            temp = 9999;
        }
        else
        {
            q.push({cur_ans+"S",cur-1});
            temp = cur -1;
        }
        if(temp == correct)
            return cur_ans + "S";
        
        temp = left_lotation(cur);
        q.push({cur_ans+"L",temp});
        if(temp==correct)
            return cur_ans+"L";
        temp = right_lotation(cur);
        q.push({cur_ans+"R",temp});
        if(temp==correct)
            return cur_ans+"R";
    }
    return "";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        memset(visit,0,sizeof(visit));
        cout<<bfs(a,b)<<"\n";
    }
}
