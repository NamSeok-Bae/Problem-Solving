import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var intersection = Set(lottos).intersection(win_nums)

    let first = 7 - (intersection.count + lottos.filter { $0 == 0 }.count)
    let second = 7 - intersection.count
    return [first >= 6 ? 6 : first , second >= 6 ? 6 : second]
}