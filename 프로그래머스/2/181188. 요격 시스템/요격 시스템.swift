import Foundation

func solution(_ targets:[[Int]]) -> Int {
    let sorted = targets.sorted(by: {
        $0[1] < $1[1]
    })
    var rocket = -1
    var turret = 0
    
    for i in sorted {
        if rocket == -1 {
            turret += 1
            rocket = i[1]
        }
        
        if rocket > i[0] && rocket <= i[1] { continue }
        
        turret += 1
        rocket = i[1]
    }
    
    return turret
}