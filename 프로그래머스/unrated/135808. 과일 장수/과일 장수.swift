import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    var sortedScore = score.sorted(by: >)
    var result = 0
    var curIdx = m - 1
    while curIdx < sortedScore.count {
        result += sortedScore[curIdx] * m
        curIdx += m
    }
    return result
}