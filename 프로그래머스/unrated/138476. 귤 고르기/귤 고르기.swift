import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var dic = [Int: Int]()

    for i in tangerine {
        if dic[i] != nil {
            dic[i]! += 1
        } else {
            dic[i] = 1
        }
    }

    var sum = 0
    var result = 0
    
    for i in dic.sorted(by: { $0.value > $1.value}) {
        if sum >= k {
            break
        } else {
            sum += i.value
            result += 1
        }
    }
    return result
}