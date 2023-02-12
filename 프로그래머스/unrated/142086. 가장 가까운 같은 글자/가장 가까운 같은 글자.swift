import Foundation

func solution(_ s:String) -> [Int] {
    var dic = [String: Int]()
    var result = [Int]()

    for (idx, i) in s.map { String($0) }.enumerated() {
        if dic[i] == nil {
            dic[i] = idx
            result.append(-1)
        } else {
            result.append(idx - dic[i]!)
            dic[i] = idx
        }
    }
    return result
}