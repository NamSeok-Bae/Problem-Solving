#include <iostream>
#include <vector>

using namespace std;

int n,m,b;
int map[501][501];
bool height[257];
vector<int> h;
int ans_time=987654321,ans_height=0;
//64000000
int main()
{
    cin>>n>>m>>b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            if(height[map[i][j]]==0)
            {
                height[map[i][j]]=1;
                h.push_back(map[i][j]);
            }
        }
    }
    for(int a =0; a <=256;a++)
    {
        int time=0,use_block=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j] == a)
                    continue;
                else if(map[i][j] < a)
                {
                    time += a-map[i][j];
                    use_block -= a-map[i][j];
                }
                else
                {
                    time += (map[i][j]-a)*2;
                    use_block += map[i][j]-a;
                }
            }
        }
        if(use_block+b < 0)
            continue;
        else
        {
            if(ans_time >= time)
            {
                ans_time = time;
                ans_height = max(ans_height,a);
            }
        }
    }
    cout<<ans_time<<" "<<ans_height;
            
}
