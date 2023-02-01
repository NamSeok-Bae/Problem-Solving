import Foundation

func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
    let todayTemp = today.split(separator: ".").map { Int(String($0))! }
    let todayYear = todayTemp[0]
    let todayMonth = todayTemp[1]
    let todayDay = todayTemp[2]
    var termDic: [String: String] = [:]
    var result: [Int] = []

    for i in terms {
        let temp = i.split(separator: " ").map { String($0) }
        termDic[temp[0]] = temp[1]
    }

    for (idx, i) in privacies.enumerated() {
        let temp = i.split(separator: " ").map { String($0) }
        let date = temp[0].split(separator: ".").map { Int(String($0))! }
        var year = date[0]
        let month = date[1]
        let day = date[2]

        let term = temp[1]
        let termMonth = Int(termDic[term]!)!

        var newMonth = month + termMonth

        while newMonth > 12 {
            year += 1
            newMonth -= 12
        }

        if todayYear > year {
            result.append(idx+1)
            continue
        } else if todayYear == year {
            if todayMonth > newMonth {
                result.append(idx+1)
                continue
            } else if todayMonth == newMonth {
                if todayDay >= day {
                    result.append(idx+1)
                    continue
                }
            }
        }
    }
    print(result)
    return result
}