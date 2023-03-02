import Foundation

func solution(_ storey:Int) -> Int {
    var numberArray = String(storey).map { Int(String($0))! }
    var result = 0

    for i in stride(from: numberArray.count - 1, through: 0, by: -1) {
        let digit = numberArray[i]

        if digit > 5 {
            if i == 0 {
                result += 11 - digit
            } else {
                result += 10 - digit
                numberArray[i-1] += 1
            }
        } else if digit == 5 {
            if i != 0 {
                if numberArray[i-1] >= 5 {
                    numberArray[i-1] += 1
                }
            }
            result += digit
        } else {
            result += digit
        }
    }
    return result
}