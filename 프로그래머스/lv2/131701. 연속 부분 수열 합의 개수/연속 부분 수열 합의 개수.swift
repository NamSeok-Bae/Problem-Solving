import Foundation

func solution(_ elements:[Int]) -> Int {
    var result = Set(elements)

    for i in stride(from: 2, through: elements.count, by: 1) {
        var maxSum = 0
        for j in stride(from: 0, to: i, by: 1) {
            maxSum += elements[j]
        }
        var tempSum = maxSum
        result.insert(tempSum)
        for j in stride(from: i, to: elements.count + i, by: 1) {
            tempSum = tempSum - elements[j - i]
            tempSum = j >= elements.count ? tempSum + elements[j - elements.count] : tempSum + elements[j]

            result.insert(tempSum)
        }
    }
    return result.count
}