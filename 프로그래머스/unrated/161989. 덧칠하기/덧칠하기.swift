import Foundation

func solution(_ n:Int, _ m:Int, _ section:[Int]) -> Int {
    var temp = section
    var result = 0
    while !temp.isEmpty {

        var curIdx = 0
        for (idx, i) in temp.enumerated() {
            if i < temp[0] + m {
                curIdx = idx
            } else {
                curIdx = idx - 1
                break
            }
        }

        for _ in 0...curIdx {
            temp.removeFirst()
        }
        result += 1
    }
    return result
}