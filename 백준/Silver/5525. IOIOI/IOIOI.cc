#include <iostream>
#include <string>

using namespace std;

int n,m;
string problem;
string s;
int cnt;

int main()
{
    cin>>n;
    cin>>m;
    cin>>problem;
    
    s = "I";
    for(int i=1;i<=n;i++)
    {
        s +="OI";
    }
    int pos = 0;
    while(problem.find(s,pos)!=string::npos)
    {
        cnt++;
        pos = problem.find(s,pos) + 2;
    }
    cout<<cnt;
}
