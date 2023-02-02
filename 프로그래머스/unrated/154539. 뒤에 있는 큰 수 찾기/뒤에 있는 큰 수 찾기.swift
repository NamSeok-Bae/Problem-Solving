import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var array = [(Int, Int)]()
    var result = Array(repeating: 0, count: numbers.count)

    for (idx, i) in numbers.enumerated() {
        while !array.isEmpty, array.last!.1 < i {
            result[array.last!.0] = i
            array.removeLast()
        }
        array.append((idx, i))
    }
    array.forEach {
        result[$0.0] = -1
    }

    return result
}