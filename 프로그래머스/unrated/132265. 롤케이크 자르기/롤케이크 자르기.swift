import Foundation

func solution(_ topping:[Int]) -> Int {
    var older = Dictionary(grouping: topping, by: { $0 })
    var younger = Set<Int>()
    var result = 0

    for i in topping {
        older[i]?.removeLast()
        younger.insert(i)
        if older[i]!.isEmpty {
            older.removeValue(forKey: i)
        }

        if younger.count == older.count {
            result += 1
        }
    }
    return result
}