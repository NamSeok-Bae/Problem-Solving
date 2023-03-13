import Foundation

func checkPosible(dic: [String: Int], discountDic: [String: Int]) -> Bool {
    for (key, value) in dic {
        if discountDic[key] != value {
            return false
        }
    }
    return true
}

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var dic = [String: Int]()
    var discountDic = [String: Int]()
    for i in 0..<want.count {
        dic[want[i]] = number[i]
    }

    for i in 0..<10 {
        if discountDic[discount[i]] == nil {
            discountDic[discount[i]] = 1
        } else {
            discountDic[discount[i]]! += 1
        }
    }

    var result = 0
    if checkPosible(dic: dic, discountDic: discountDic) {
        result += 1
    }

    for i in stride(from: 10, to: discount.count, by: 1) {
        discountDic[discount[i-10]]! -= 1
        if discountDic[discount[i]] == nil {
            discountDic[discount[i]] = 1
        } else {
            discountDic[discount[i]]! += 1
        }

        if checkPosible(dic: dic, discountDic: discountDic) {
            result += 1
        }
    }
    return result
}