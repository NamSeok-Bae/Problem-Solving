func swap(_ a: inout Int, _ b: inout Int) {
    if(a < b) {
        var temp = a
        a = b
        b = temp
    }
}

func gcd(_ a: Int, _ b: Int) -> Int {
    var temp = 0
    var aa = a
    var bb = b
    while bb != 0 {
        temp = aa % bb
        aa = bb
        bb = temp
    }
    return aa
}

func lcm(_ a: Int, _ b: Int, _ g: Int) -> Int {
    return (a * b) / g
}

func solution(_ n:Int, _ m:Int) -> [Int] {
    var a = n
    var b = m
    swap(&a, &b)
    let g = gcd(a, b)
    let l = lcm(a, b, g)
    
    return [g, l]
}