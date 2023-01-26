#include <iostream>

using namespace std;

int n,l,cnt;
int map[101][101];

void solve()
{
    int i=0,j=0;
    bool check = false;
    bool prev = false;
    while(1)
    {
        if(i>=n)
            break;
        if(j==n-1)
        {
            cnt++;
            i++;
            j=0;
            prev = false;
        }
        
        check = false;
        if(map[i][j] == map[i][j+l] - 1 && j+l < n) // map[i][j] < map[i][j+l]
        {
            for(int k=0;k<l;k++)
            {
                if(map[i][j+k] != map[i][j])
                {
                    check = true;
                    break;
                }
            }
            if(!check)
            {
                if(prev)
                {
                    if(map[i][j]==map[i][j+1])
                    {
                        j++;
                        prev = false;
                    }
                    else
                    {
                        i++;
                        j=0;
                        prev = false;
                    }
                }
                else
                {
                    j+=l;
                }
            }
            else
            {
                i++;
                j=0;
                prev = false;
            }
        }
        else if(map[i][j] == map[i][j+l] + 1 && j+l < n) // map[i][j] > map[i][j+l]
        {
            for(int k=1;k<=l;k++)
            {
                if(map[i][j+k] != map[i][j+l])
                {
                    check = true;
                    break;
                }
            }
            if(!check)
            {
                j+=l;
                prev = true;
            }
            else
            {
                if(map[i][j] == map[i][j+1])
                    j++;
                else
                {
                    i++;
                    j=0;
                    prev = false;
                }
            }
        }
        else if(map[i][j] == map[i][j+1])
        {
            j++;
            prev = false;
        }
        else
        {
            i++;
            j=0;
            prev = false;
        }
    }
    i=j=0;
    prev = false;
    check = false;
    while(1)
    {
        if(j>=n)
            break;
        if(i==n-1)
        {
            cnt++;
            j++;
            i=0;
            prev = false;
        }
        
        check = false;
        if(map[i][j] == map[i+l][j] - 1 && i+l < n) // map[i][j] < map[i][j+l]
        {
            for(int k=0;k<l;k++)
            {
                if(map[i+k][j] != map[i][j])
                {
                    check = true;
                    break;
                }
            }
            if(!check)
            {
                if(prev)
                {
                    if(map[i][j] == map[i+1][j])
                    {
                        i++;
                        prev = false;
                    }
                    else
                    {
                        i=0;
                        j++;
                        prev = false;
                    }
                }
                else
                {
                    i+=l;
                }
            }
            else
            {
                j++;
                i=0;
                prev = false;
            }
        }
        else if(map[i][j] == map[i+l][j] + 1 && i+l < n) // map[i][j] > map[i][j+l]
        {
            for(int k=1;k<=l;k++)
            {
                if(map[i+k][j] != map[i+l][j])
                {
                    check = true;
                    break;
                }
            }
            if(!check)
            {
                i+=l;
                prev = true;
            }
            else
            {
                if(map[i][j] == map[i+1][j])
                    i++;
                else
                {
                    j++;
                    i=0;
                    prev = false;
                }
            }
        }
        else if(map[i][j] == map[i+1][j])
        {
            i++;
            prev = false;
        }
        else
        {
            j++;
            i=0;
            prev = false;
        }
    }
}

int main()
{
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    }
    solve();
    cout<<cnt;
}
