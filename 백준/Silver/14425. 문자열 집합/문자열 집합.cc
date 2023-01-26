#include <iostream>
#include <string>
#include <map>

using namespace std;

int n,m,cnt;
string s;
map<string,int> M;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        M[s]++;
    }
    for(int i=0;i<m;i++)
    {
        string temp; cin>>temp;
        if(M[temp])
            cnt++;
    }
    cout<<cnt;
}
