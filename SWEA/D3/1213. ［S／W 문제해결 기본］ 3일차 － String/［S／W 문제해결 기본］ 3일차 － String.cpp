#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a; cin>> a;
        string word; cin>>word;
        string str; cin>>str;
        
        int cnt = 0;
        
        while(str.find(word) != string::npos) {
            cnt++;
            str = str.substr(str.find(word) + word.size());
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
