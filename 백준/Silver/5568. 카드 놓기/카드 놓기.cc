#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <cstring>

using namespace std;
bool visit[11];
int n,k;
int arr[11];
unordered_set<string> us;

void find_pair(string s, int counter)
{
    if(counter != k)
    {
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                visit[i] = true;
                find_pair(s+to_string(arr[i]), counter+1);
                visit[i] = false;
            }
            
        }
    }
    else
        us.insert(s);
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    find_pair("", 0);
    cout<<us.size();
}
