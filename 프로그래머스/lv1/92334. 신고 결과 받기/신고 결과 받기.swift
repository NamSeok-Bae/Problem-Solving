import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var s = Set(report)
    var dic = [String: [String]]()
    var accumulateDic = [String: Int]()
    var result = [Int]()

    for i in s {
        let temp = i.split(separator: " ").map { String($0) }
        if accumulateDic[temp[1]] == nil {
            accumulateDic[temp[1]] = 1
        } else {
            accumulateDic[temp[1]]! += 1
        }
        if dic[temp[0]] == nil {
            dic[temp[0]] = [temp[1]]
        } else {
            dic[temp[0]]?.append(temp[1])
        }
    }

    id_list.forEach {
        var cnt = 0
        if let dic = dic[$0] {
            for i in dic {
                if accumulateDic[i]! >= k {
                    cnt += 1
                }
            }
        }
        result.append(cnt)
    }
    return result
}