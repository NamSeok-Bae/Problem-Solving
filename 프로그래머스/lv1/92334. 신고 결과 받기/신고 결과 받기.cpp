#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> m;
int pos;
vector<int> v[1001];
bool visit[1001][1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(int i=0;i<id_list.size();i++)
    {
        m[id_list[i]] = i;
        answer.push_back(0);
    }
    for(int i=0;i<report.size();i++)
    {
        string s= report[i];
        pos = report[i].find(" ",0);
        string a= report[i].substr(0,pos);
        string b = report[i].substr(pos+1,report[i].size());
        if(visit[m[a]][m[b]])
            continue;
        v[m[b]].push_back(m[a]);
        visit[m[a]][m[b]] = 1;
    }
    for(int i=0;i<id_list.size();i++)
    {
        if(v[i].size()<k)
            continue;
        for(auto a : v[i])
        {
            answer[a]++;
        }
    }
    return answer;
}