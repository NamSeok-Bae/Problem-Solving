import Foundation

func solution(_ babbling:[String]) -> Int {
    let baby = ["aya", "ye", "woo", "ma"]
    var result = 0
    for i in babbling {
        var isExist = false
        var s = i
        var preString = ""
        while true {
            for j in baby {
                if s.prefix(j.count) == j && preString != j {
                    preString = j
                    s.removeFirst(j.count)
                    isExist = true
                    break
                }
            }

            if isExist {
                isExist = false
            } else if !isExist || s.isEmpty {
                break
            }
        }

        result += s.isEmpty ? 1 : 0
    }
    return result
}