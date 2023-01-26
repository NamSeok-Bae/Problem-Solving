#include <iostream>
#include <string>

using namespace std;

int k;
string s;

int main()
{
    cin>>k>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i%k==0)
            cout<<s[i];
    }
}
