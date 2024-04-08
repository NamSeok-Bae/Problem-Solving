#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin>>n;
        stack<char> st;
        string s = "";
        for(int i=0;i<n;i++) {
            char a; cin>>a;
            
            if(a - '0' >= 0 && a - '0' <= 9) {
                s += a;
            } else if(a == '(') {
                st.push(a);
            } else if(a==')') {
                while(!st.empty() && st.top() != '(') {
                    s += st.top();
                    st.pop();
                }
                st.pop();
            } else if(a=='*' || a=='/') {
                if(st.empty()) {
                    st.push(a);
                    continue;
                }
                
                while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    s += st.top();
                    st.pop();
                }
                st.push(a);
            } else if(a=='+' || a=='-') {
                if(st.empty()) {
                    st.push(a);
                    continue;
                }
                
                while(!st.empty() && st.top() != '(') {
                    s += st.top();
                    st.pop();
                }
                st.push(a);
            }
        }
        while(!st.empty()) {
            s+=st.top();
            st.pop();
        }
        stack<int> st_int;
        for(int i=0;i<s.size();i++) {
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                st_int.push(s[i]-'0');
            } else {
                int b = st_int.top();
                st_int.pop();
                int a = st_int.top();
                st_int.pop();
                
                switch (s[i]) {
                    case '+':
                        st_int.push(a+b);
                        break;
                    case '-':
                        st_int.push(a-b);
                        break;
                    case '*':
                        st_int.push(a*b);
                        break;
                    case '/':
                        st_int.push(a/b);
                }
            }
        }
        cout<<"#"<<test_case<<" "<<st_int.top()<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
