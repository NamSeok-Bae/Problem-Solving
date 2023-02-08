import Foundation
import CoreFoundation

func solution(_ x:Int, _ y:Int, _ n:Int) -> Int {
var dp = Array(repeating: 987654321, count: y+1)

dp[x] = 0

for cur in stride(from: x, to: y, by: 1) {
    if cur + n <= y {
        dp[cur+n] = min(dp[cur] + 1, dp[cur+n])
    }
    if cur * 2 <= y {
        dp[cur * 2] = min(dp[cur] + 1, dp[cur*2])
    }
    if cur * 3 <= y {
        dp[cur * 3] = min(dp[cur] + 1, dp[cur*3])
    }
}
    if dp[y] == 987654321 {
        return -1
    }
    
    return dp[y]
}