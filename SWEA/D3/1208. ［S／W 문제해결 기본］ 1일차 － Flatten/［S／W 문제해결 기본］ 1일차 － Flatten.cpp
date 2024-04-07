#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin>>n;
        map<int,int, greater<int>> m;
        
        for(int i=1;i<=100;i++) {
            int a; cin>> a;
            m[a]++;
        }
        
        while(n >= 1) {
            int max_height = m.begin()->first;
            int min_height = (--m.end())->first;
            
            if(max_height - min_height >= 2) {
                n--;
                m[max_height]--;
                m[max_height-1]++;
                m[min_height+1]++;
                m[min_height]--;
                
                if(m[max_height] == 0) {
                    m.erase(max_height);
                }
                if(m[min_height] == 0) {
                    m.erase(min_height);
                }
            } else {
                break;
            }
        }
        int max_height = m.begin()->first;
        int min_height = (--m.end())->first;
        
        cout<<"#"<<test_case<<" "<<max_height - min_height<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

