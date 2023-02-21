import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    var result: Int64 = Int64(money) - Int64(price) * (Int64(count) * Int64(count+1)) / 2
    
    return result < 0 ? abs(result) : 0
}