#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int parent[22] = {0};
int t;

int find_parent(int x){
    if(parent[x] != x)
        return parent[x] = find_parent(parent[x]);
    return x;
}
void merge(int a, int b){
    int x = find_parent(a);
    int y = find_parent(b);
 
    if(x != y){
        if(x < y) // 그룹번호가 더 작은 쪽으로 합치기
            parent[y] = x;
        else
            parent[x] = y;
    }
}

int main() {
    while(true) {
        t++;
        int n; cin>>n;
        if(n==0) {return 0;}
        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
        vector<string> v;
        map<string, int> m;
        for(int i=0;i<n;i++) {
            string s1, s2; cin>>s1>>s2;
            
            if(m[s1] == 0) {
                v.push_back(s1);
                m[s1] = v.size();
            }
            
            if(m[s2] == 0) {
                v.push_back(s2);
                m[s2] = v.size();
            }
            
            merge(m[s1], m[s2]);
        }
        
        set<int> s;
        for(int i=1;i<=n;i++) {
            s.insert(parent[i]);
        }
        cout<< t << " " << s.size() << "\n";
    }
}
