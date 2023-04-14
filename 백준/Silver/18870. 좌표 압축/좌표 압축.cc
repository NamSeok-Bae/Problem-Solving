#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
vector<int> v;
map<int, int> m;
vector<int> temp;

int main() {
    cin>>n;
    while(n--) {
        int num; cin>> num;
        temp.push_back(num);
        if(m[num]==0) {
            v.push_back(num);
            m[num]++;
        }
    }
    sort(v.begin(), v.end());
    
    for(auto i : temp) {
        cout<< lower_bound(v.begin(), v.end(), i) - v.begin()<<" ";
    }
}
