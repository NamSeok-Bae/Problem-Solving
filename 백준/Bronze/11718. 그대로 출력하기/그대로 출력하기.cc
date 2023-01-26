#include <iostream>
#include <algorithm>

using namespace std;
string s;
int main()
{
    while(1)
    {
        getline(cin,s);
        if(s=="")
            break;
        cout<<s<<"\n";
    }
}
