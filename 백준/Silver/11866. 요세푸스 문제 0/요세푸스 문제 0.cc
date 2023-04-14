#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
vector<int> v;
vector<int> result;

int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        v.push_back(i);
    }
    
    auto it = v.begin() - 1;
    while(!v.empty()) {
        for(int i=1;i<=k;i++) {
            advance(it, 1);
            if(it == v.end()) {
                it = v.begin();
            }
        }
        result.push_back(*it);
        v.erase(it);
        advance(it, -1);
    }
    cout<<"<";
    for(int i=0;i<result.size();i++) {
        cout<<result[i];
        if(i!= result.size()-1) {
            cout<<", ";
        }
    }
    cout<<">";
}
