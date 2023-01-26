#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp ="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            temp+=s[i];
            continue;
        }
        if(s[i]=='o')
        {
            i+=2;
            temp+="1";
        }
        else if(s[i]=='z')
        {
            i+=3;
            temp+="0";
        }
        else if(s[i]=='e')
        {
            i+=4;
            temp+="8";
        }
        else if(s[i]=='n')
        {
            i+=3;
            temp+="9";
        }
        else if(s[i]=='t')
        {
            if(s[i+1]=='w')
            {
                i+=2;
                temp+="2";
            }
            else
            {
                i+=4;
                temp+="3";
            }
        }
        else if(s[i]=='f')
        {
            if(s[i+1]=='o')
            {
                i+=3;
                temp+="4";
            }
            else
            {
                i+=3;
                temp+="5";
            }
        }
        else if(s[i]=='s')
        {
            if(s[i+1]=='i')
            {
                i+=2;
                temp+="6";
            }
            else
            {
                i+=4;
                temp+="7";
            }
        }
    }
    stringstream ss(temp);
    ss>>answer;
    return answer;
}