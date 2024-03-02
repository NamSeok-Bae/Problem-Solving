#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool validate_palindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while(end > start) {
        if(s[start] != s[end]) {
            return false;
        }
        
        start++;
        end--;
    }
    
    return true;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s; cin>> s;
        int str_length = s.length();
        string left_substr = s.substr(0, (str_length-1)/2);
        string right_substr = s.substr((str_length+1)/2);
        
        bool result = validate_palindrome(s) && validate_palindrome(left_substr) && validate_palindrome(right_substr);
        
        cout<< "#" << test_case<< " ";
        
        if(result) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
