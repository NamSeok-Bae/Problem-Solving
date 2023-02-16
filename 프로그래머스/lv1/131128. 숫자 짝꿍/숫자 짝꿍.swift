import Foundation

func solution(_ X:String, _ Y:String) -> String {
    var xCnt = [0,0,0,0,0,0,0,0,0,0]
    var yCnt = [0,0,0,0,0,0,0,0,0,0]

    for i in X {
        xCnt[Int(String(i))!] += 1
    }

    for i in Y {
        yCnt[Int(String(i))!] += 1
    }

    var result = ""

    for i in 0...9 {
        if xCnt[i] == 0 || yCnt[i] == 0 {
            continue
        }

        if xCnt[i] == yCnt[i] {
            for _ in 1...xCnt[i] {
                result.append("\(i)")
            }
        } else {
            for _ in 1...(xCnt[i] <= yCnt[i] ? xCnt[i] : yCnt[i]) {
                result.append("\(i)")
            }
        }
    }
    if result.isEmpty {
        return "-1"
    } else {
        result = result.map { String($0) }.sorted { return Int($0)! > Int($1)! }.joined()
        if result.first! == "0" {
            return "0"
        } 
        return result
    }
}