import Foundation

func solution(_ n:Int) -> Int {
    let s = String(n, radix: 3)
    return Int(String(s.reversed()), radix: 3)!
}