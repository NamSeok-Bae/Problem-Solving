import Foundation

func solution(_ picks:[Int], _ minerals:[String]) -> Int {
    var tempMinerals = minerals.reversed().map {String($0)}
    var mineralZips = [[String]]()
    var tempPicks = picks
    var result = 0
    var pickCount = picks.reduce(0, +)

    var count = 0
    while !tempMinerals.isEmpty {
        var minerals = [String]()
        count += 1
        while !tempMinerals.isEmpty {
            if minerals.count == 5 {
                break
            }

            minerals.append(tempMinerals.removeLast())
        }
        mineralZips.append(minerals)

        if count == pickCount {
            break
        }
    }

    mineralZips.sort { A, B in
        var diaA = 0
        var ironA = 0
        var diaB = 0
        var ironB = 0
        for i in A {
            if i == "diamond" {
                diaA += 1
            } else if i == "iron" {
                ironA += 1
            }
        }

        for i in B {
            if i == "diamond" {
                diaB += 1
            } else if i == "iron" {
                ironB += 1
            }
        }

        if diaA != diaB {
            return diaA > diaB
        }
        return ironA > ironB
    }

    while !mineralZips.isEmpty {
        if let pick = tempPicks.firstIndex(where: { $0 > 0 }) {
            let zips = mineralZips.removeFirst()
            tempPicks[pick] -= 1
            switch pick {
            case 0:
                result += zips.count
            case 1:
                let diaCount = zips.filter { $0 == "diamond"}.count
                result += diaCount * 5 + zips.count - diaCount
            case 2:
                var diaCount = 0
                var ironCount = 0
                for i in zips {
                    if i == "diamond" {
                        diaCount += 1
                    } else if i == "iron" {
                        ironCount += 1
                    }
                }
                result += diaCount * 25 + ironCount * 5 + zips.count - diaCount - ironCount
            default:
                break
            }
        } else {
            break
        }
    }
    return result
}