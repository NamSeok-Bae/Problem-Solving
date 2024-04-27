import Foundation

func validate_change(_ a: [String], _ b: [String]) -> Bool {
    if(a.count != b.count) { return false }
    if(a == b) { return false }
    var count = 0
    for i in 0..<a.count {
        if(a[i] != b[i]) {
            count += 1
        }
    }
    
    return count >= 2 ? false : true
}

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var q: [(String, Int)] = [] // queue
    var dic: [String: Bool] = [:]
    var idx = 0
    
    q.append((begin, 0))
    dic[begin] = true
    
    while(q.count > idx) {
        let cur_word = q[idx].0
        let cnt = q[idx].1
        idx += 1
        
        for i in words {
            if !validate_change(cur_word.map { String($0) }, i.map { String($0) }) { continue }
            if let _ = dic[i] { continue }
            
            if(i == target) {
                return cnt + 1
            }
            q.append((i, cnt + 1))
            dic[i] = true
        }
    }
    
    return 0
}