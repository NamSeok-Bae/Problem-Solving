import Foundation

func solution(_ s:String) -> Int {
    var temp = s.map { String($0) }
var result = 0
var first = ""
var cnt1 = 0
var cnt2 = 0

for i in temp {
    if cnt1 == 0 {
        first = i
        cnt1 += 1
    } else {
        if first == i {
            cnt1 += 1
        } else {
            cnt2 += 1
        }
        
        if cnt1 == cnt2 {
            result += 1
            first = ""
            cnt1 = 0
            cnt2 = 0
        }
    }
}

if first != "" {
    result += 1
}
    return result
}