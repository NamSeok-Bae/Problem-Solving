func solution(_ num:Int) -> Int {
    
    var temp = num
    var cnt = 0
    
    while true {
        if temp == 1 || cnt == 500 { break }
        
        cnt += 1
        if temp % 2 == 0 {
            temp /= 2
        } else {
            temp *= 3
            temp += 1
        }
    }
    
    return temp == 1 ? cnt : -1
}