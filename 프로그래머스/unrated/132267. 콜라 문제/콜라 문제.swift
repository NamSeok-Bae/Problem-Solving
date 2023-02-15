import Foundation

func solution(_ a:Int, _ b:Int, _ n:Int) -> Int {
    var cur = n
    var result = 0

    while cur >= a {
        var temp = (cur / a) * b
        cur = temp + (cur % a)
        result += temp
    }
    return result
}