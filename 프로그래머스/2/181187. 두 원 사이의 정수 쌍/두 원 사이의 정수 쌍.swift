import Foundation

func solution(_ r1:Int, _ r2:Int) -> Int64 {
    var result: Int64 = 0
    
    for i in 1...r2 {
        var r1_count: Double = 0
        var r2_count: Double = 0
        r1_count = ceil(sqrt(Double(r1*r1 - i*i)))
        r2_count = floor(sqrt(Double(r2*r2 - i*i)))
        
        if r1_count.isNaN { r1_count = 0 }
        
        result += Int64(r2_count - r1_count + 1)
    }
    
    return result * 4
}