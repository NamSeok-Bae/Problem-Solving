import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var intersection = Set(lottos).intersection(win_nums)

    return [min(7 - (intersection.count + lottos.filter { $0 == 0 }.count), 6), min(7 - intersection.count, 6)]
}