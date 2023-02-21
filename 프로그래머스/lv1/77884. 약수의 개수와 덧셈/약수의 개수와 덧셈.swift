import Foundation

func solution(_ left:Int, _ right:Int) -> Int {
    var result = 0

    for i in stride(from: left, through: right, by: 1) {
        var s = Set<Int>()
        let sqrtNum = sqrt(Double(i))
        for j in stride(from: 1, through: sqrt(Double(i)), by: 1) {
            if i % Int(j) == 0 {
                s.insert(Int(j))
                s.insert(i/Int(j))
            }
        }
        result = s.count % 2 == 1 ? result - i : result + i
    }
    return result
}