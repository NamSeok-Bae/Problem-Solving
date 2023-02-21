import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    let sorted_sizes = sizes.map { $0.sorted { $0 > $1 } }

    var maxFirst = 0, maxSecond = 0
    for i in sorted_sizes {
        if i[0] > maxFirst {
            maxFirst = i[0]
        }
        if i[1] > maxSecond {
            maxSecond = i[1]
        }
    }

    return maxFirst * maxSecond
}