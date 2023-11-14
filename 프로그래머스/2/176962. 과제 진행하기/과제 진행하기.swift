import Foundation

func solution(_ plans:[[String]]) -> [String] {
    var blocked: [(String, Int, Int)] = [] // 과제이름, 남은시간
    var processing: (String, Int, Int)? = nil
    var plans = plans.map { ($0[0], timeToInt(time: $0[1]), Int($0[2])!) }.sorted(by: {
        $0.1 < $1.1
    })
    var result: [String] = []
    
    while true {
        if let process = processing {
            if !plans.isEmpty {
                let plan = plans[0]
                let processTime = process.1 + process.2
                
                if processTime < plan.1 {
                    result.append(process.0)
                    if !blocked.isEmpty {
                        let blocked = blocked.removeLast()
                        processing = (blocked.0, processTime, blocked.2)
                    } else {
                        processing = plans.removeFirst()
                    }
                } else if processTime == plan.1 {
                    result.append(process.0)
                    processing = plans.removeFirst()
                } else {
                    blocked.append((process.0, process.1, processTime - plan.1))
                    processing = plans.removeFirst()
                }
            } else {
                result.append(process.0)
                if !blocked.isEmpty {
                    while !blocked.isEmpty {
                        result.append(blocked.removeLast().0)
                    }
                }
                return result
            }
        } else {
            processing = plans.removeFirst()
        }
    }
}

func timeToInt(time: String) -> Int {
    let time = time.split(separator: ":").map { Int(String($0))! }
    let hour = time[0] * 60
    let min = time[1]
    
    return hour + min
}