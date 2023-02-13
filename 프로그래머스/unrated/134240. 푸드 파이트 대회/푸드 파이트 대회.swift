import Foundation

func solution(_ food:[Int]) -> String {
    var leftResult = [Int]()
    var rightResult = [Int]()
    var result = ""

    for i in 1..<food.count {
        if food[i] >= 2 {
            var temp = food[i]/2
            for _ in 1...temp {
                leftResult.append(i)
                rightResult.insert(i, at: 0)
            }
        }
    }

    for i in leftResult {
        result.append("\(i)")
    }
    result.append("0")
    for i in rightResult {
        result.append("\(i)")
    }

    return result
}