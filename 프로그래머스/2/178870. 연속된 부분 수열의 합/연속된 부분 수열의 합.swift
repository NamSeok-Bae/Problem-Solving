import Foundation

func solution(_ sequence:[Int], _ k:Int) -> [Int] {
    var s = 0, e = 0
    var length = 987654321
    var sum = sequence[0]
    var result = (0, 0)
    
    while s <= e && e < sequence.count {
        if sum < k {
            if e + 1 == sequence.count { break }
            e += 1
            sum += sequence[e]
        } else if sum == k {
            if e-s+1 < length {
                length = e-s+1
                result = (s, e)
            } else if e-s+1 == length {
                if s < result.0 {
                    result = (s, e)
                }
            }
            sum -= sequence[s]
            s += 1
        } else {
            sum -= sequence[s]
            s += 1
        }
    }
    
    return [result.0, result.1]
}