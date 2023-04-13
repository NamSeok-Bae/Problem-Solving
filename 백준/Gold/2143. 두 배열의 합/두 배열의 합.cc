#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int t;
int n,m;
vector<long long> n_v;
vector<long long> m_v;
long long n_arr[1001];
long long m_arr[1001];
long long result;

int main() {
    cin>>t;
    cin>>n;
    long long sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>n_arr[i];
    }
    for(int i=1;i<=n;i++) {
        n_v.push_back(n_arr[i]);
        sum = n_arr[i];
        for(int j=i+1;j<=n;j++) {
            sum += n_arr[j];
            n_v.push_back(sum);
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>m_arr[i];
    }
    for(int i=1;i<=m;i++) {
        m_v.push_back(m_arr[i]);
        sum = m_arr[i];
        for(int j=i+1;j<=m;j++) {
            sum += m_arr[j];
            m_v.push_back(sum);
        }
    }
    
    sort(m_v.begin(),m_v.end());
    
    for(auto i : n_v) {
        long long diff = t - i;
        
        auto up = upper_bound(m_v.begin(), m_v.end(), diff);
        auto low = lower_bound(m_v.begin(), m_v.end(), diff);
        result += (up - low);
    }
    cout<<result;
}
