import Foundation

func solution(_ keymap:[String], _ targets:[String]) -> [Int] {
    var dic = [String: Int]()

    for i in keymap {
        for (idx, j) in i.map({ String($0) }).enumerated() {
            if dic[j] == nil {
                dic[j] = idx + 1
            } else {
                dic[j] = min(dic[j]!, idx + 1)
            }
        }
    }

    var result = [Int]()
    for i in targets {
        var sum = 0
        for j in i.map({ String($0) }) {
            if dic[j] == nil {
                sum = -1
                break
            } else {
                sum += dic[j]!
            }
        }
        result.append(sum)
    }
    return result
}