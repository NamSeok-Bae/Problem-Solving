import Foundation

func solution(_ arr:[Int], _ idx:Int) -> Int {
    
    let temp = arr.enumerated().map { ($0.offset, $0.element) }.firstIndex {
        $0.0 >= idx && $0.1 == 1
    }.map { Int($0) }
    
    guard let idx = temp else {
        return -1
    }
    
    return idx
}