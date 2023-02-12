import Foundation

func solution(_ weights:[Int]) -> Int64 {
    var dic = [Int: Int]()
var result: Int64 = 0

for i in weights {
    dic[i] = dic[i] == nil ? 1 : dic[i]! + 1
}
let sorted_dic = dic.sorted(by:<)

for (key, i) in sorted_dic {
    if i > 1 {
        result += Int64((i*(i-1))/2)
    }
    
    if (key*4)%3 == 0 && dic[(key*4)/3] != nil {
        result += Int64(dic[(key*4)/3]!) * Int64(i)
    }
    
    if dic[(key*2)] != nil {
        result += Int64(dic[(key*2)]!) * Int64(i)
    }
    
    if (key*3)%2 == 0 && dic[(key*3)/2] != nil {
        result += Int64(dic[(key*3)/2]!) * Int64(i)
    }
}
    return result
}