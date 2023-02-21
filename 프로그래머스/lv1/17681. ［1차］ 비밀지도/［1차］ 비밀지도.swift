func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    return  (0..<n).map {
        let binary = String(arr1[$0] | arr2[$0], radix: 2)
        let string = String(repeating: "0", count: n - binary.count) + binary
        return string.reduce("") { $0 + ($1 == "0" ? " " : "#") }
    }
}