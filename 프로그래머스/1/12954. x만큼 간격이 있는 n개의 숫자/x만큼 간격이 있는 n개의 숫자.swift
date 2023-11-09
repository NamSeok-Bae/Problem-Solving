func solution(_ x:Int, _ n:Int) -> [Int64] {
    return (0..<n).map { Int64($0 * x + x) }
}