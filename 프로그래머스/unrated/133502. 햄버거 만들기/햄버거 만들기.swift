import Foundation

func solution(_ ingredient:[Int]) -> Int {
    var array = [Int]()
    var result = 0

    for i in ingredient {
        array.append(i)

        if Array(array.suffix(4)) == [1,2,3,1] {
            array.removeLast(4)
            result += 1
        }
    }
    return result
}