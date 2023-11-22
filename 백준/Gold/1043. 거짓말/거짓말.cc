#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int parent[53];

int find_parent(int x) {
    if(parent[x] != x)
        return parent[x] = find_parent(parent[x]);
    return x;
}

void merge(int a, int b) {
    int x = find_parent(a);
    int y = find_parent(b);
    
    if(x!=y) {
        if(x<y) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
    }
}

int main() {
    int n,m; cin>>n>>m;
    int result = m;
    int a; cin>> a;
    vector<int> v[51];
    
    for(int j=0;j<=n;j++) {
        parent[j] = j;
    }
    
    for(int i=0;i<a;i++) {
        int temp; cin>>temp;
        parent[temp] = 0;
    }
    
    for(int i=0;i<m;i++) {
        cin>>a;
        
        int temp; cin>> temp;
        v[i].push_back(temp);
        for(int j=1;j<a;j++) {
            int temp2; cin>>temp2;
            v[i].push_back(temp2);
            merge(temp, temp2);
        }
    }
    
    for(int i=0;i<m;i++) {
        for(auto a : v[i]) {
            if(find_parent(a) == 0) {
                result--;
                break;
            }
        }
    }
    cout<<result;
}
