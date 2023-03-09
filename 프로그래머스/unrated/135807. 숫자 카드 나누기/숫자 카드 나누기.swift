import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 {
        return a
    } else {
        return gcd(b, a%b)
    }
}

func checkDivisor(gcd: Int, array: [Int]) -> Int {
    for i in array {
        if i % gcd == 0 {
            return 0
        }
    }
    return gcd
}

func solution(_ arrayA:[Int], _ arrayB:[Int]) -> Int {
    var a = arrayA[0]
    for i in arrayA {
        a = gcd(a, i)
    }

    var b = arrayB[0]
    for i in arrayB {
        b = gcd(b, i)
    }

    return max(checkDivisor(gcd: a, array: arrayB), checkDivisor(gcd: b, array: arrayA))
}