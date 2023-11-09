func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var y_result = [[Int]]()
    for i in 0..<arr1.count {
        var x_result = [Int]()
        for j in 0..<arr1[i].count {
            x_result.append(arr1[i][j] + arr2[i][j])
        }
        y_result.append(x_result)
    }
    return y_result
}