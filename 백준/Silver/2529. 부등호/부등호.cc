#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> num;
vector<char> problem;
vector<int> v; // 0~9 순열 담기
vector<vector<int>> ans;
bool visit[10];
bool check;

void np()
{
    if(v.size()==n+1)
    {
        int temp = v[0];
        int idx = 0;
        for(int i=1;i<v.size();i++)
        {
            if(problem[idx] == '<')
            {
                if(temp > v[i])
                    return;
            }
            else
            {
                if(temp < v[i])
                    return;
            }
            temp = v[i];
            idx++;
        }
        ans.push_back(v);
        return;
    }
    
    for(int i =0;i<=9;i++)
    {
        if(visit[i])
            continue;
        
        visit[i] = true;
        v.push_back(i);
        np();
        visit[i] =false;
        v.pop_back();
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<=9;i++)
        num.push_back(i);
    
    for(int i=0;i<n;i++)
    {
        char a; cin>>a;
        problem.push_back(a);
    }
    np();
    for(auto a : ans[ans.size()-1])
        cout<<a;
    cout<<endl;
    for(auto a : ans[0])
        cout<<a;
}
