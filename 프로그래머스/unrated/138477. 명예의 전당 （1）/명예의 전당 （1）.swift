import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var frame = [Int]()
var result = [Int]()

for i in score {
    if frame.count < k {
        frame.append(i)
        result.append(frame.min()!)
    } else {
        frame.append(i)
        frame.sort(by: >)
        frame.removeLast()
        result.append(frame[k-1])
    }
}
    return result
}