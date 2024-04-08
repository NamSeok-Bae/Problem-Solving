#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin>>n;
        char arr[201];
        int cnt = 0;
        for(int i=0;i<n;i++) {
            int a; cin>>a;
            char b; cin>>b;
            
            if(b >= '0' && b <='9') {
                cnt++;
            }
            string s;
            getline(cin, s);
            
            arr[a] = b;
        }
        bool isAble = true;
        while(cnt--) {
            if(!(arr[n] >= '0' && arr[n] <= '9')) {
                isAble = false;
                break;
            }
            n--;
        }
        cout<<"#"<<test_case<<" "<<isAble<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
