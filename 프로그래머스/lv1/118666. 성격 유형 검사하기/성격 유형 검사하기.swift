import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var array = [(Int, Int)](repeating: (0, 0), count: 4) // RT CF JM AN
    var string_array = ["RT", "CF", "JM", "AN"]
    var result = ""

    for i in 0..<survey.count {
        let temp = survey[i].map { String($0) }
        let point = choices[i] - 4

        if point < 0 {
            switch temp.first! {
            case "R":
                array[0].0 += abs(point)
            case "T":
                array[0].1 += abs(point)
            case "C":
                array[1].0 += abs(point)
            case "F":
                array[1].1 += abs(point)
            case "J":
                array[2].0 += abs(point)
            case "M":
                array[2].1 += abs(point)
            case "A":
                array[3].0 += abs(point)
            case "N":
                array[3].1 += abs(point)
            default:
                break
            }
        } else {
            switch temp.last! {
            case "R":
                array[0].0 += abs(point)
            case "T":
                array[0].1 += abs(point)
            case "C":
                array[1].0 += abs(point)
            case "F":
                array[1].1 += abs(point)
            case "J":
                array[2].0 += abs(point)
            case "M":
                array[2].1 += abs(point)
            case "A":
                array[3].0 += abs(point)
            case "N":
                array[3].1 += abs(point)
            default:
                break
            }
        }
    }

    for (idx, i) in array.enumerated() {
        if i.0 == i.1 || i.0 > i.1  {
            result.append(string_array[idx].first!)
        } else {
            result.append(string_array[idx].last!)
        }
    }
    return result
}