import Foundation

func solution(_ cards:[Int]) -> Int {
    var result = 0
    for (idx, i) in cards.enumerated() {
        var check = Array(repeating: false, count: cards.count + 1)
        var cur = i
        check[idx + 1] = true
        var count = 1
        while true {
            if check[cur] == true {
                break
            }

            check[cur] = true
            cur = cards[cur - 1]
            count += 1
        }
        for (jdx, j) in cards.enumerated() where check[jdx + 1] == false {
            var check2 = check
            var cur2 = j
            check2[jdx + 1] = true
            var count2 = 1
            while true {
                if check2[cur2] == true {
                    break
                }

                check2[cur2] = true
                cur2 = cards[cur2 - 1]
                count2 += 1
            }
            result = max(result, count * count2)
        }
    }
    return result
}