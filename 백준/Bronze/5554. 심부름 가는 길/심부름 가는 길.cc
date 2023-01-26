#include <iostream>

using namespace std;

int main()
{
    int a;
    int sum=0;
    
    for(int i=0; i<4; i++)
    {
        cin>>a;
        sum=sum+a;
}
    cout<<sum/60<<endl;
    cout<<sum%60;
}