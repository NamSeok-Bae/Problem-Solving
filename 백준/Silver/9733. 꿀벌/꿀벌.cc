#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, double> um;
vector<string> vs;
double cnt;
int main()
{
    string s;
    while(getline(cin,s) && s.size() != 0)
    {
        vs.push_back(s);
    }
    for(auto a: vs)
    {
        string temp;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] != ' ')
            {
                temp += a[i];
            }
            if(temp.size() == 2)
            {
                um[temp]++;
                cnt++;
                temp = "";
            }
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<"Re"<<" "<<int(um["Re"])<<" "<<um["Re"]/cnt<<"\n";
    cout<<"Pt"<<" "<<int(um["Pt"])<<" "<<um["Pt"]/cnt<<"\n";
    cout<<"Cc"<<" "<<int(um["Cc"])<<" "<<um["Cc"]/cnt<<"\n";
    cout<<"Ea"<<" "<<int(um["Ea"])<<" "<<um["Ea"]/cnt<<"\n";
    cout<<"Tb"<<" "<<int(um["Tb"])<<" "<<um["Tb"]/cnt<<"\n";
    cout<<"Cm"<<" "<<int(um["Cm"])<<" "<<um["Cm"]/cnt<<"\n";
    cout<<"Ex"<<" "<<int(um["Ex"])<<" "<<um["Ex"]/cnt<<"\n";
    cout<<"Total"<<" "<<int(cnt)<<" "<<"1.00";
}
