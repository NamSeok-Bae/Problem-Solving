import Foundation

func solution(_ players:[String], _ callings:[String]) -> [String] {
    var nameDic = [Int: String]()
    var rankDic = [String: Int]()

    for (idx, i) in players.enumerated() {
        nameDic[idx] = i
        rankDic[i] = idx
    }

    callings.forEach {
        guard let currentRank = rankDic[$0],
              let forwardName = nameDic[currentRank - 1] else { return }
        nameDic[currentRank - 1] = $0
        nameDic[currentRank] = forwardName

        rankDic[$0] = currentRank - 1
        rankDic[forwardName] = currentRank
    }

    return nameDic.sorted(by: { $0.key < $1.key }).map { $0.value }
}