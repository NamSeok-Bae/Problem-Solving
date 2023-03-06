import Foundation

func solution(_ data:[[Int]], _ col:Int, _ row_begin:Int, _ row_end:Int) -> Int {
    let sortedData = data.sorted {
        if $0[col-1] == $1[col-1] {
            return $0[0] > $1[0]
        }
        return $0[col-1] < $1[col-1]
    }

    var result = [Int]()
    for i in stride(from: row_begin, through: row_end, by: 1) {
        result.append(sortedData[i-1].map { $0 % i }.reduce(0, +))
    }
    return result.reduce(0, ^)
}