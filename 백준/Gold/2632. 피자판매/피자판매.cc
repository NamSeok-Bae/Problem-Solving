#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k, m, n;
long long arr[1001];
long long brr[1001];
vector<long long> a;
vector<long long> b;
long long result;
long long sum;

int main() {
    cin>>k;
    cin>>m>>n;
    for(int i=0;i<m;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++) {
        a.push_back(arr[i]);
        sum = arr[i];
        if(i==m-1) {
            for(int j=0;j<m-1;j++) {
                sum += arr[j];
                a.push_back(sum);
            }
        } else {
            for(int j=1;j<m-1;j++) {
                sum += arr[(i+j)%m];
                a.push_back(sum);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cin>>brr[i];
    }
    for(int i=0;i<n;i++) {
        b.push_back(brr[i]);
        sum = brr[i];
        if(i == n-1) {
            for(int j=0;j<n-1;j++) {
                sum +=brr[j];
                b.push_back(sum);
            }
        }else {
            for(int j=1;j<n-1;j++) {
                sum += brr[(i+j)%n];
                b.push_back(sum);
            }
        }
    }
    a.push_back(0);
    b.push_back(0);
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(auto i : a) {
        auto up = upper_bound(b.begin(), b.end(), k-i);
        auto low = lower_bound(b.begin(), b.end(), k-i);
        result += up - low;
    }
    cout<<result;
}
