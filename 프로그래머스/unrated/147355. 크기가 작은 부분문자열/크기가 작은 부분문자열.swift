import Foundation

func solution(_ t:String, _ p:String) -> Int {
    let pCnt = p.count - 1
    var result = 0
    for (idx, _) in t.enumerated() {
        if idx >= t.count - pCnt { break }

        let startIndex = t.index(t.startIndex, offsetBy: idx)
        let endIndex = t.index(startIndex, offsetBy: pCnt)
        let s = t[startIndex...endIndex]

        if Int(s)! <= Int(p)! { result += 1}
    }
    return result
}