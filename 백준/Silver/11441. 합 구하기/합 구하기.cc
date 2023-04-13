#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        int a,b; cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<"\n";
    }
}
