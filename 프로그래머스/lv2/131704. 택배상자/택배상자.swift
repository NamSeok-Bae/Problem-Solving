import Foundation

func solution(_ order:[Int]) -> Int {
    var tempOrder = order.reversed().map { Int($0) }
    var forward = Array(stride(from: order.count, through: 1, by: -1))
    var backward = [Int]()
    var result = [Int]()

    while true {
        guard let firstOrder = tempOrder.last else { break }

        if forward.last == firstOrder {
            tempOrder.removeLast()
            forward.removeLast()
            result.append(firstOrder)
        } else {
            if backward.last == firstOrder {
                result.append(backward.removeLast())
                tempOrder.removeLast()
            } else if !backward.isEmpty && backward.last! > firstOrder {
                break
            } else {
                backward.append(forward.removeLast())
            }
        }
    }
    return result.count
}