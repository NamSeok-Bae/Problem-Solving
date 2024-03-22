#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[101][101];
int arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++) {
        int a = puddles[i][0];
        int b = puddles[i][1];
        
        arr[b][a] = 1;
    }
    
    dp[1][1] = 1;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i == 1 && j == 1)  {
                dp[i][j] = 1;
                continue;
            } 
            
            if(arr[i][j] != 1) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
    }
    
    return dp[n][m];
}