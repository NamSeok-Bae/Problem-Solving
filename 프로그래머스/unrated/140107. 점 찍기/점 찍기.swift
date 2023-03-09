import Foundation

func solution(_ k:Int, _ d:Int) -> Int64 {
    var result: Int64 = 0
    for i in stride(from: 0, through: d, by: k) {
        let temp = Int(sqrt(Double(d*d - i*i)))/k
        result += Int64(temp + 1)
    }
    return result
}