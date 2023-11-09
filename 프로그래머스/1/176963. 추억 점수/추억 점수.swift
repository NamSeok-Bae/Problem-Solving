import Foundation

func solution(_ name:[String], _ yearning:[Int], _ photo:[[String]]) -> [Int] {
    var m: [String: Int] = [:]
    for i in 0..<name.count {
        m[name[i]] = yearning[i]
    }
    
    return photo.map { $0.map { name in m[name] ?? 0 }.reduce(0, +) }
}