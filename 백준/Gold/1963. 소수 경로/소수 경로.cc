#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int t;
int first,second;

int number = 10000; // 구하고자 하는 소수의 범위
int primeNum[10001];

bool visit[10001];

void primeNumber(){
    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
}
void bfs()
{
    queue<pair<int,int>> q;
    q.push({first,0});
    visit[first] = true;
    while(!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == second)
        {
            cout<<cnt<<"\n";
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int next;
            for(int j=0;j<10;j++)
            {
                string s = to_string(cur);
                s[i] = j+'0';
                next = stoi(s);
                if(!visit[next] && primeNum[next] != 0 && (next>1000 && next<10000))
                {
                    q.push({next,cnt+1});
                    visit[next] = true;
                }
            }
        }
    }
    cout<<"Impossible\n";
}
int main()
{
    cin>>t;
    primeNumber();
    while(t--)
    {
        cin>>first>>second;
        memset(visit,0,sizeof(visit));
        bfs();
    }
}
