#include <iostream>
#include <string>

using namespace std;

string s;
string temp;
bool checkError;
bool isUpper;
bool isUnder;

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isUnder && isUpper)
            checkError = true;
        
        if(i==0)
        {
            if(s[i]=='_')
                checkError = true;
            else if(s[i]>='A' && s[i]<='Z')
                checkError = true;
            else
                temp += s[i];
        }
        else
        {
            if(s[i-1]=='_')
            {
                if(s[i]=='_')
                    checkError = true;
                else if(s[i]>='A' && s[i]<='Z')
                    checkError = true;
                else
                    temp+=s[i];
            }
            else if(s[i-1] >='A' && s[i-1]<='Z')
            {
                if(s[i]=='_')
                    checkError = true;
                else
                    temp+=s[i];
            }
            else if(i==(s.size()-1))
            {
                if(s[i]=='_')
                    checkError=true;
                else
                    temp+=s[i];
            }
            else
                temp+=s[i];
            
            if(temp[i]>='A' && temp[i]<='Z')
                isUpper = true;
            if(temp[i]=='_')
                isUnder = true;
        }
    }
    if(checkError)
    {
        cout<<"Error!\n";
        return 0;
    }
    else
    {
        int pos = 0;
        pos = temp.find('_',pos);
        if(pos == string::npos)
        {
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]>='a' && temp[i]<='z')
                    cout<<temp[i];
                else
                    cout<<"_"<<char(temp[i]+32);
            }
        }
        else
        {
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]>='a' && temp[i]<='z')
                    cout<<temp[i];
                else
                    cout<<char(temp[++i]-32);
            }
        }
        cout<<"\n";
    }
}
