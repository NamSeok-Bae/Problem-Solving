#include <iostream>
#include <algorithm>

using namespace std;

int n,ans = -1e9;
char arr[20];

int cal(int a,int b, char oper)
{
    switch (oper) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
    }
    return -1;
}

void dfs(int index, int cur)
{
    if(index >= n-1)
    {
        ans = max(ans,cur);
        return;
    }
    
    if(index + 4 < n)
    {
        int temp = cal(arr[index+2]-'0',arr[index+4]-'0',arr[index+3]);
        dfs(index+4,cal(cur,temp,arr[index+1]));
    }
    
    dfs(index+2,cal(cur,arr[index+2]-'0',arr[index+1]));
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    dfs(0,arr[0]-'0');
    cout<<ans;
}
