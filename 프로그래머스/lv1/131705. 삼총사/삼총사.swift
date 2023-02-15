import Foundation

func solution(_ number:[Int]) -> Int {
    var array = [Int]()
    var result = 0
    func combination(cur: Int) {
        if array.count == 3 {
            let num = array.reduce(0) { $0 + $1 }
            if num == 0 {
                result += 1
            }
        } else {
            for i in cur..<number.count {
                array.append(number[i])
                combination(cur: i + 1)
                array.removeLast()
            }
        }
    }
    combination(cur: 0)
    return result
}