#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1000001][2];

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    
    
    
    dp[1][0] = money[0];
    
    for(int i=3;i<n;i++) {
        if(i==3) {
            dp[i][0] = money[i-1] + dp[i-2][0];
        } else if(i==4) {
            dp[i][0] = money[i-1] + dp[i-3][0];
        } else {
            dp[i][0] = max(dp[i-2][0],dp[i-3][0]) + money[i-1];
        }
    }
    
    dp[2][1] = money[1];
    dp[3][1] = max(money[1], money[2]);
    
    for(int i=4;i<=n;i++) {
        if(i==4) {
            dp[i][1] = money[i-1] + dp[i-2][1];
        } else {
            dp[i][1] = max(dp[i-2][1], dp[i-3][1]) + money[i-1];
        }
    }
    
    return max(max(dp[n-1][0], dp[n-2][0]), max(dp[n][1],dp[n-1][1]));
}