#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1001];
vector<long long> v;
int result;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    
    sort(arr, arr + n + 1);
    
    int sum = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            v.push_back(arr[i] + arr[j]);
        }
    }
    
    sort(v.begin(), v.end());
    for(int i=n; i>=1;i--) {
        for(int j=i;j >= 1; j--) {
            bool isExist = binary_search(v.begin(), v.end(), arr[i] - arr[j]);
            if(isExist) {
                cout<<arr[i];
                return 0;
            }
        }
    }
}
