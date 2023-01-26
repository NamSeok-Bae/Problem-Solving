#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int arr[5][9];
bool visit[5];
string s;
int k;

void rotation(int num, int dir)
{
    if(dir==-1)
    {
        int temp = arr[num][1];
        for(int i=2;i<=8;i++)
        {
            arr[num][i-1] = arr[num][i];
        }
        arr[num][8] = temp;
    }
    else
    {
        int temp = arr[num][8];
        for(int i=7;i>=1;i--)
        {
            arr[num][i+1] = arr[num][i];
        }
        arr[num][1] = temp;
    }
}

void solve(int num,int dir)
{
    if(num+1 <= 4)
    {
        if(arr[num][3] != arr[num+1][7] && visit[num+1]==false)
        {
            visit[num+1] = true;
            solve(num+1, -dir);
        }
    }
    if(num-1 >= 1)
    {
        if(arr[num][7] != arr[num-1][3] && visit[num-1]==false)
        {
            visit[num-1] = true;
            solve(num-1,-dir);
        }
    }
    rotation(num, dir);
}

int main()
{
    for(int i=1;i<=4;i++)
    {
        cin>>s;
        for(int j=0;j<8;j++)
            arr[i][j+1] = s[j]-'0';
    }
    cin>>k;
    while(k--)
    {
        int num,dir;
        cin>>num>>dir;
        memset(visit,false,sizeof(visit));
        visit[num] = true;
        solve(num,dir);
    }
    int sum = 0;
    for(int i=1;i<=4;i++)
    {
        sum += (arr[i][1])*pow(2,i-1);
    }
    cout<<sum;
}
