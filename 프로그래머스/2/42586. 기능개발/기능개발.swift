import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var arr = Array(repeating: 0, count: progresses.count)
    
    for (idx, i) in progresses.enumerated() {
        var v = (100 - i) / speeds[idx]
        let r = (100 - i) % speeds[idx]
        if r != 0 {
            v += 1
        }
        
        if(idx == 0) {
            arr[idx] = v
        } else {
            arr[idx] = arr[idx-1] > v ? arr[idx-1] : v
        }
    }
    
    var dic: [Int: Int] = [:]
    
    for i in arr {
        if let value = dic[i] {
            dic.updateValue(value + 1, forKey: i)
        } else {
            dic[i] = 1
        }
    }
    
    return dic.sorted { $0.key < $1.key }.map { $0.value }
}
