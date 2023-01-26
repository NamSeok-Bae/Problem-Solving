#include <iostream>
#include <string>

using namespace std;

string f,s;
int cnt,arr[10001];

int main()
{
    cin>>f>>s;
    int f_size = f.length(),s_size = s.length();
    int next = 0;
    while(f_size || s_size || next)
    {
        int f_num = 0,s_num =0;
        if(f_size)
            f_num = f[(f_size--)-1]-'0';
        if(s_size)
            s_num = s[(s_size--)-1]-'0';
        
        arr[cnt++] = (f_num + s_num+next)%10;
        
        if(f_num + s_num+next >= 10)
            next = 1;
        else
            next = 0;
    }
    for(int i=cnt-1;i>=0;i--)
        cout<<arr[i];
}
